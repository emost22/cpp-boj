#include <iostream>
#include <queue>
#define MAX 501
using namespace std;
typedef pair<int, int> pii;

char list[MAX][MAX];
int visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, H, D;
int sx, sy;

bool isMove(int x, int y, int hd) {
	if (list[x][y] == 'U' || list[x][y] == 'E') return true;
	return hd > 1;
}

int bfs() {
	queue<pair<pii, pii> > q;
	q.push({ {H, 0}, {sx, sy} });
	visit[sx][sy] = H;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().second.first;
			int y = q.front().second.second;
			int h = q.front().first.first;
			int u = q.front().first.second;
			q.pop();

			if (list[x][y] == 'E') {
				return t;
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];
				int nh = h;
				int nu = u;

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (!isMove(nx, ny, h + u)) continue;
				
				if (list[nx][ny] == 'U') {
					nu = D;
				}
				if (list[nx][ny] != 'E') {
					if (nu) nu--;
					else nh--;
				}
				if (visit[nx][ny] >= nh + nu) continue;

				q.push({ {nh, nu}, {nx,ny} });
				visit[nx][ny] = nh + nu;
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> N >> H >> D;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < N; j++) {
			if (list[i][j] == 'S') {
				sx = i;
				sy = j;
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