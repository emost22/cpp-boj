#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<int> party[50], num[51];
bool chk[51], visit[51][51];
int N, M, K, P, a, ans;

void bfs() {
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < num[v].size(); i++) {
			int next = num[v][i];

			if (chk[next]) continue;
			chk[next] = true;
			q.push(next);
		}
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			int v = party[i][j];

			if (chk[v]) {
				ans++;
				break;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	if (!K) {
		for (int i = 0; i < M; i++) {
			cin >> P;
			for (int j = 0; j < P; j++) {
				cin >> a;
			}
		}
		cout << M << '\n';
	}
	else {
		for (int i = 0; i < K; i++) {
			cin >> a;
			chk[a] = true;
			q.push(a);
		}

		for (int i = 0; i < M; i++) {
			cin >> P;
			for (int j = 0; j < P; j++) {
				cin >> a;
				
				party[i].push_back(a);
				for (int k = 0; k < j; k++) {
					int prev = party[i][k];
	
					if (!visit[prev][a]) {
						num[a].push_back(prev);
						num[prev].push_back(a);
						visit[prev][a] = true;
						visit[a][prev] = true;
					}
				}
			}
		}

		bfs();
		solve();

		cout << M - ans << '\n';
	}

	return 0;
}