#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

typedef struct Point {
	int v;
	int cost;
	int t;
}Point;

bool cmp(Point a, Point b) {
	return a.t < b.t;
}

vector<Point> graph[101];
int d[101][10001];
int N, M, K;

void dijkstra() {
	priority_queue < pair<int, pair<int, int> > > q;
	q.push({ 0, {0, 1} });
	d[1][0] = 0;
	while (!q.empty()) {
		int x = q.top().second.second;
		int t = -q.top().first;
		int cost = q.top().second.first;
		q.pop();

		if (t > d[x][cost]) continue;

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i].v;
			int nextcost = cost + graph[x][i].cost;
			int nexttime = t + graph[x][i].t;

			if (nextcost > M) continue;

			if (d[next][nextcost] > nexttime) {
				d[next][nextcost] = nexttime;
				for (int j = nextcost + 1; j <= M; j++) {
					if (d[next][j] <= nexttime) break;
					d[next][j] = nexttime;
				}
				q.push({ -nexttime, {nextcost, next} });
			}
		}
	}

	if (d[N][M] == INF) cout << "Poor KCM\n";
	else cout << d[N][M] << '\n';
}

void func() {
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}

	dijkstra();
}

void init() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
		for (int j = 1; j <= 10000; j++) {
			d[i][j] = INF;
		}
	}
}

void input() {
	int u, v, c, t;
	cin >> N >> M >> K;
	init();
	while (K--) {
		cin >> u >> v >> c >> t;
		graph[u].push_back({ v,c,t });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}