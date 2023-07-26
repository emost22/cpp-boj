#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> v[MAX];
bool visit[MAX];
int N;

bool dfs(int x) {
	visit[x] = true;

	for (auto y : v[x]) {
		if (visit[y]) return false;
		if (!dfs(y)) return false;

		visit[y] = false;
	}

	return true;
}

void func() {
	if (dfs(1)) cout << "NO CYCLE\n";
	else cout << "CYCLE\n";
}

void input() {
	int M, x;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> M;
		while (M--) {
			cin >> x;
			v[i].push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}