#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
typedef long long ll;

vector<pair<ll, ll> > graph[501];
ll d[501], N, M;
bool chk;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	ll u, v, w;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	for (int i = 2; i <= N; i++) d[i] = INF;

	for (int t = 0; t < N; t++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				ll next = graph[i][j].first;
				ll nextdis = graph[i][j].second;

				if (d[i] != INF && d[next] > d[i] + nextdis) {
					d[next] = d[i] + nextdis;
					if (t == N - 1) chk = true;
				}
			}
		}
	}

	if (chk) cout << "-1\n";
	else {
		for (int i = 2; i <= N; i++) {
			if (d[i] == INF) d[i] = -1;
			cout << d[i] << '\n';
		}
	}

	return 0;
}