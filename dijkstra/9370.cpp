#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > weight[2001];
priority_queue<int> des;
int N, M, T, S, G, H, a, b, d;

vector<int> dijkstra(int v) {
	vector<int> dis(N + 1, INF);
	priority_queue<pair<int, int> > q;
	q.push({ 0, v });
	dis[v] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		int nowdis = -q.top().first;
		q.pop();

		if (dis[now] < nowdis) continue;

		for (int i = 0; i < weight[now].size(); i++) {
			int next = weight[now][i].first;
			int nextdis = weight[now][i].second;

			if (dis[next] > dis[now] + nextdis) {
				dis[next] = dis[now] + nextdis;
				q.push({ -nextdis, next });
			}
		}
	}
	return dis;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		int ST, SG, GH, HT, SH, HG, GT;
		cin >> N >> M >> T;
		cin >> S >> G >> H;

		for (int i = 0; i < M; i++) {
			cin >> a >> b >> d;
			weight[a].push_back({ b, d });
			weight[b].push_back({ a, d });
		}
		for (int i = 0; i < T; i++) {
			cin >> a;
			des.push(-a);
		}

		vector<int> result = dijkstra(S);
		vector<int> g = dijkstra(G);
		vector<int> h = dijkstra(H);
		while (!des.empty()) {
			int t = -des.top();
			des.pop();

			ST = result[t];
			SG = result[G];
			SH = result[H];
			GH = g[H];
			GT = g[t];
			HG = h[G];
			HT = h[t];

			if (ST == SG + GH + HT || ST == SH + HG + GT) {
				cout << t << ' ';
			}
		}
		cout << '\n';

		for (int i = 1; i <= N; i++) weight[i].clear();
	}

	return 0;
}