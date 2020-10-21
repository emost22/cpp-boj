#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
vector<int> station[1000], num[100001];
bool visit[100001], stationchk[1000];
int N, K, M, ans = -1;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == N) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < num[x].size(); i++) {
			int idx = num[x][i];
			if (stationchk[idx]) continue;
			for (int j = 0; j < station[idx].size(); j++) {
				int next = station[idx][j];
				if (!visit[next]) {
					q.push({ next, cnt + 1 });
					visit[next] = true;
				}
			}
			stationchk[idx] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> n;
			station[i].push_back(n);
			num[n].push_back(i);
		}
	}

	q.push({ 1, 1 });
	visit[1] = true;
	bfs();

	cout << ans << '\n';

	return 0;
}