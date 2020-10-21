#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000000
using namespace std;

vector<int> graph[20001];
int d[20001];
int N, M, ans, idx, cnt;

void init() {
	for (int i = 2; i <= N; i++) {
		d[i] = INF;
	}
}

void dijkstra(int v) {
	priority_queue<pair<int, int> > q;
	q.push({ 0, v });
	while (!q.empty()) {
		int now = q.top().second;
		int dis = -q.top().first;
		q.pop();

		if (d[now] < dis) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			
			if (d[next] > dis + 1) {
				d[next] = dis + 1;
				q.push({ -(dis + 1), next });
			}
		}
	}
}

void solve() {
	for (int i = 2; i <= N; i++) {
		if (ans <= d[i]) {
			if (ans == d[i]) cnt++;
			else {
				idx = i;
				cnt = 1;
			}
			ans = d[i];
		}
	}

	cout << idx << ' ' << ans << ' ' << cnt << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	init();
	dijkstra(1);
	solve();

	return 0;
}