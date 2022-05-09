#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 21
using namespace std;
typedef pair<int, int> pi;

vector<pi> v;
int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, vCnt;

int bfs() {
	memset(visit, false, sizeof(visit));

	int ret = 0;
	queue<pi> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] != 2 || visit[i][j]) continue;

			q.push({ i,j });
			visit[i][j] = true;
			int cnt = 0;
			bool flag = false;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				cnt++;
				for (int d = 0; d < 4; d++) {
					int nx = x + direct[d][0];
					int ny = y + direct[d][1];

					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (list[nx][ny] == 1 || visit[nx][ny]) continue;

					if (!list[nx][ny]) {
						flag = true;
						continue;
					}

					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}
			if (flag) cnt = 0;
			ret += cnt;
		}
	}

	return ret;
}

void func() {
	int ans = 0;
	for (int i = 0; i < vCnt - 1; i++) {
		for (int j = i + 1; j < vCnt; j++) {
			int x1 = v[i].first;
			int y1 = v[i].second;
			int x2 = v[j].first;
			int y2 = v[j].second;

			list[x1][y1] = 1;
			list[x2][y2] = 1;
			ans = max(ans, bfs());
			list[x1][y1] = 0;
			list[x2][y2] = 0;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (!list[i][j]) {
				v.push_back({ i,j });
			}
		}
	}
	vCnt = v.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
		
	return 0;
}