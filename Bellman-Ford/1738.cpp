#include <iostream>
#include <vector>
#include <cstring>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > weight[101];
bool cycle, visit[101];
int parent[101], d[101];
int N, M, u, v, w;

void init() {
	for (int i = 2; i <= N; i++) {
		d[i] = INF;
	}
}

void dfs(int s) {
	if (s == N) {
		cycle = true;
		return;
	}

	visit[s] = true;
	for (int i = 0; i < weight[s].size(); i++) {
		if (!visit[weight[s][i].first]) {
			dfs(weight[s][i].first);
		}
	}
}

void print(int s) {
	if (s == 1) {
		cout << s << ' ';
		return;
	}
	visit[s] = true;

	if (!visit[parent[s]]) {
		print(parent[s]);
		cout << s << ' ';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	init();
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		weight[u].push_back({ v, -w });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < weight[j].size(); k++) {
				int next = weight[j][k].first;
				int dis = weight[j][k].second;

				if (d[j] != INF && d[next] > d[j] + dis) {
					parent[next] = j;
					d[next] = d[j] + dis;

					if (i == N - 1) dfs(j);
				}
			}
		}
	}

	if (cycle) cout << "-1\n";
	else {
		memset(visit, false, sizeof(visit));
		print(N);
		cout << '\n';
	}

	return 0;
}