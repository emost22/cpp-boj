#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

vector<int> graph[MAX];
pi indepth[MAX];
int conn[MAX], depth[MAX];
int t, N, M;

void print() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, depth[i]);
	}

	cout << t << ' ' << ans << '\n';
}

void func() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!conn[i]) {
			q.push(i);
			depth[i] = 1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		int d = depth[x];
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			conn[next]--;
			if (d > indepth[next].first) {
				indepth[next].first = d;
				indepth[next].second = 1;
			}
			else {
				indepth[next].second++;
			}

			if (!conn[next]) {
				q.push(next);
				if (indepth[next].second > 1) {
					depth[next] = indepth[next].first + 1;
				}
				else {
					depth[next] = indepth[next].first;
				}
			}
		}
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
		conn[i] = 0;
		indepth[i] = { 0,0 };
		depth[i] = 0;
	}
}

void input() {
	int u, v;
	cin >> t >> N >> M;
	while (M--) {
		cin >> u >> v;

		graph[u].push_back(v);
		conn[v]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		init();
		input();
		func();
		print();
	}

	return 0;
}