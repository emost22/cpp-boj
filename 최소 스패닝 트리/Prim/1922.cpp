#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > list[1001];
bool visit[1001];
int N, M, ans, cnt;

void func() {
	priority_queue<pair<int, int> > q;
	visit[1] = true;
	for (int i = 0; i < list[1].size(); i++) {
		q.push({ -list[1][i].second, list[1][i].first });
	}

	while (!q.empty()) {
		int x = q.top().second;
		int w = -q.top().first;
		q.pop();

		if (visit[x]) continue;
		visit[x] = true;
		ans += w;
		cnt++;
		if (cnt == N - 1) break;
		for (int i = 0; i < list[x].size(); i++) {
			int next = list[x][i].first;
			int nextw = list[x][i].second;

			q.push({ -nextw, next });
		}
	}

	cout << ans << '\n';
}

void input() {
	int u, v, w;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v >> w;
		list[u].push_back({ v,w });
		list[v].push_back({ u,w });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}