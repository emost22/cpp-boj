#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> f[501];
bool visit[501];
int N, M, ans;

void func() {
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < f[v].size(); i++) {
			if (!visit[f[v][i]]) {
				visit[f[v][i]] = true;
				ans++;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		f[a].push_back(b);
		f[b].push_back(a);
	}

	visit[1] = true;
	for (int i = 0; i < f[1].size(); i++) {
		visit[f[1][i]] = true;
		q.push(f[1][i]);
		ans++;
	}
	func();

	cout << ans << '\n';

	return 0;
}