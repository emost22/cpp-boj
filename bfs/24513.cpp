#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

queue<pii> oneq, twoq;
int list[MAX][MAX], visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, ans[3];

void bfs() {
	for (int t = 1; !oneq.empty() || !twoq.empty(); t++) {
		int oqsize = oneq.size();
		int tqsize = twoq.size();

		while (oqsize--) {
			int x = oneq.front().first;
			int y = oneq.front().second;
			oneq.pop();

			if (visit[x][y] == 3) {
				visit[x][y] = -1;
				continue;
			}

			ans[0]++;
			visit[x][y] = -1;
			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny] || list[nx][ny] == -1) continue;

				oneq.push({ nx,ny });
				visit[nx][ny] = 1;
			}
		}

		while (tqsize--) {
			int x = twoq.front().first;
			int y = twoq.front().second;
			twoq.pop();

			ans[1]++;
			visit[x][y] = -1;
			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny] == 1) {
					visit[nx][ny] = 3;
					ans[2]++;
					continue;
				}
				if (visit[nx][ny] || list[nx][ny] == -1) continue;
				
				twoq.push({ nx,ny });
				visit[nx][ny] = 2;
			}
		}
	}
}

void func() {
	bfs();
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (list[i][j] == 1) {
				oneq.push({ i,j });
				visit[i][j] = -1;
			}
			else if (list[i][j] == 2) {
				twoq.push({ i,j });
				visit[i][j] = -1;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}