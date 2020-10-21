#include <iostream>
#include <vector>
#include <cstring>
#define INF 1000000000
using namespace std;
typedef long long ll;

vector<pair<int, int> > weight[100];
bool visit[100], cycle, ans;
ll d[100], getmoney[100];
int N, S, E, M, u, v, w;

void init() {
	for (int i = 0; i < N; i++) {
		if(i != S) d[i] = INF;
	}
}

void find(int s) {	
	if (s == E) ans = 1;

	visit[s] = true;

	for (int i = 0; i < weight[s].size(); i++) {
		if (!visit[weight[s][i].first]) {
			find(weight[s][i].first);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S >> E >> M;
	init();
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		weight[u].push_back({ v, w });
	}

	for (int i = 0; i < N; i++) {
		cin >> getmoney[i];
	}

	d[S] = -getmoney[S];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < weight[j].size(); k++) {
				int next = weight[j][k].first;
				int cost = weight[j][k].second;

				if (d[j] != INF && d[next] > d[j] + cost - getmoney[next]) {
					d[next] = d[j] + cost - getmoney[next];
					if (i == N - 1) {
						find(j);
						if (ans) cycle = true;
						ans = 0;
						memset(visit, false, sizeof(visit));
					}
				}
			}
		}
	}

	if (cycle) {
		find(S);
		if (ans) cout << "Gee\n";
		else cout << "gg\n";
	}
	else {
		if (d[E] == INF) cout << "gg\n";
		else cout << -d[E] << '\n';
	}

	return 0;
}