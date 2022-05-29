#include <iostream>
#include <queue>
#define MAX_N 10
#define MAX_M 9
using namespace std;
typedef pair<int, int> pii;

bool visit[MAX_N][MAX_M];
int directFirst[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int directSecond[4][2] = { {-1,1},{1,1},{1,-1},{-1,-1} };
pii a, b;

int bfs() {
	queue<pii> q;
	q.push({ a.first,a.second });
	visit[a.first][a.second] = true;
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + directFirst[d][0];
				int ny = y + directFirst[d][1];

				if (nx < 0 || ny < 0 || nx >= MAX_N || ny >= MAX_M) continue;
				if (nx == b.first && ny == b.second) continue;

				int nnx = nx;
				int nny = ny;
				for (int i = 0; i < 2; i++) {
					nnx += directSecond[d][0];
					nny += directSecond[d][1];

					if (nnx < 0 || nny < 0 || nnx >= MAX_N || nny >= MAX_M) continue;
					if (nnx == b.first && nny == b.second) {
						if (i) return t;
						else break;
					}

					if (i) {
						if (visit[nnx][nny]) continue;
						q.push({ nnx,nny });
						visit[nnx][nny] = true;
					}
				}

				int nd = (d + 1) % 4;
				nnx = nx;
				nny = ny;
				for (int i = 0; i < 2; i++) {
					nnx += directSecond[nd][0];
					nny += directSecond[nd][1];

					if (nnx < 0 || nny < 0 || nnx >= MAX_N || nny >= MAX_M) continue;
					if (nnx == b.first && nny == b.second) {
						if (i) return t;
						else break;
					}

					if (i) {
						if (visit[nnx][nny]) continue;
						q.push({ nnx,nny });
						visit[nnx][nny] = true;
					}
				}
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> a.first >> a.second >> b.first >> b.second;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}