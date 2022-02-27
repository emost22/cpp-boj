#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
bool visit[MAX];
int N, s, ans;

void dfs(int x) {
	visit[x] = true;
	ans++;

	if (x - list[x] > 0 && !visit[x - list[x]]) dfs(x - list[x]);
	if (x + list[x] <= N && !visit[x + list[x]]) dfs(x + list[x]);
}

void func() {
	dfs(s);
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	cin >> s;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}