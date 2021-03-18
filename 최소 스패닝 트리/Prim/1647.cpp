#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) {a > b ? a : b}
using namespace std;

vector<pair<int, int> > list[100001];
bool visit[100001];
int N, M, ans, cnt;

void func() {
	priority_queue<pair<int, int> > q;
	int maxcost = 0;
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
		maxcost = max(maxcost, w);
		ans += w;
		cnt++;
		if (cnt == N - 1) break;

		for (int i = 0; i < list[x].size(); i++) {
			int next = list[x][i].first;
			int nextw = list[x][i].second;

			q.push({ -nextw, next });
		}
	}

	cout << ans - maxcost << '\n';
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