#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<int> v[MAX];
bool visit[MAX];
int dep[MAX];
int N, S, D;

int dfs(int x) {
	visit[x] = true;

	for (auto next : v[x]) {
		if (visit[next]) continue;
		dep[x] = max(dep[x], dfs(next) + 1);
	}

	return dep[x];
}

void func() {
	dfs(S);

	int ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += (dep[i] >= D);
	}
	cout << max(0, ((ret - 1) << 1)) << '\n';
}

void input() {
	int x, y;
	cin >> N >> S >> D;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}