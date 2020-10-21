#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > weight[501];
bool cyclechk;
int edge[501][501];
int d[501], N, M, W, s, e, t;

void init() {
	d[1] = 0;
	for (int i = 2; i <= N; i++) {
		d[i] = INF;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			edge[i][j] = INF;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		cin >> N >> M >> W;
		init();

		for (int i = 0; i < M; i++) {
			cin >> s >> e >> t;
			
			edge[s][e] = min(edge[s][e], t);
			edge[e][s] = min(edge[e][s], t);
		}
		for (int i = 0; i < W; i++) {
			cin >> s >> e >> t;
			
			edge[s][e] = min(edge[s][e], -t);
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (edge[i][j] < INF) {
					weight[i].push_back({ j, edge[i][j] });
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < weight[j].size(); k++) {
					int next = weight[j][k].first;
					int dis = weight[j][k].second;

					if (d[next] > d[j] + dis) {
						d[next] = d[j] + dis;
						if (i == N) cyclechk = true;
					}
				}
			}
		}

		if (cyclechk) cout << "YES\n";
		else cout << "NO\n";

		cyclechk = false;
		for (int i = 1; i <= N; i++) weight[i].clear();
	}

	return 0;
}