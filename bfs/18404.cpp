#include <iostream>
#include <queue>
#include <cstring>
#define MAX_N 501
#define MAX_M 1001
using namespace std;
typedef pair<int, int> pii;

int visit[MAX_N][MAX_M];
int direct[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2} };
int ans[MAX_M];
int N, M, sx, sy;

void func() {
	queue<pii> q;
	q.push({ sx,sy });
	visit[sx][sy] = 0;
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int d = 0; d < 8; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
				if (!visit[nx][ny]) continue;

				if (visit[nx][ny] > 0) {
					ans[visit[nx][ny]] = t;
				}
				q.push({ nx,ny });
				visit[nx][ny] = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	memset(visit, -1, sizeof(visit));

	int x, y;
	cin >> N >> M >> sx >> sy;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		visit[x][y] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}