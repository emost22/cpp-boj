#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > list[300001];
int d[300001];
int N, M, K, start;

void solve() {
	bool chk = false;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			chk = true;
			cout << i << '\n';
		}
	}

	if (!chk) cout << "-1\n";
}

void dijkstra() {
	d[start] = 0;
	priority_queue<pair<int, int> > q;
	q.push({ start, 0 });
	while (!q.empty()) {
		int now = q.top().first;
		int dis = -q.top().second;
		q.pop();

		if (d[now] < dis) continue;

		for (int i = 0; i < list[now].size(); i++) {
			int next = list[now][i].first;
			int nextdis = dis + list[now][i].second;

			if (d[next] > nextdis) {
				d[next] = nextdis;
				q.push({ next, -nextdis });
			}
		}
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
}

void input() {
	int u, v;
	cin >> N >> M >> K >> start;
	init();

	while (M--) {
		cin >> u >> v;
		list[u].push_back({ v,1 });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dijkstra();
	solve();

	return 0;
}