#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > list[10001];
int d[10001];
int N, M;

void dijkstra() {
	priority_queue<pair<int, int> > q;
	q.push({ 0, 0 });
	d[0] = 0;
	while (!q.empty()) {
		int x = q.top().second;
		int dis = -q.top().first;
		q.pop();

		if (d[x] < dis) continue;

		for (int i = 0; i < list[x].size(); i++) {
			int next = list[x][i].first;
			int nextdis = dis + list[x][i].second;

			if (d[next] > nextdis) {
				d[next] = nextdis;
				q.push({ -nextdis, next });
			}
		}
		
		if (x + 1 <= M && d[x + 1] > dis + 1) {
			d[x + 1] = dis + 1;
			q.push({ -(dis + 1), x + 1 });
		}
	}

	cout << d[M] << '\n';
}

void input() {
	int u, v, w;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> u >> v >> w;
		list[u].push_back({ v,w });
	}
	fill(d, d + 10001, INF);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dijkstra();

	return 0;
}