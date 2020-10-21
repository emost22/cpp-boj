#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<pair<int, int>, pair<int, int> >, int> > q;
char map[10][10];
bool visit[10][10][10][10];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N, M, dx, dy, ans = -1, rcheck, bcheck;

void bfs(int rx, int ry, int bx, int by, int cnt) {
	for (int i = 0; i < 4; i++) {
		int rxx = rx, ryy = ry;
		int bxx = bx, byy = by;
		while (map[rxx][ryy] != '#') {
			rxx += x_direct[i];
			ryy += y_direct[i];

			if (map[rxx][ryy] == 'O') {
				rcheck = 1;
				break;
			}
		}
		while (map[bxx][byy] != '#') {
			bxx += x_direct[i];
			byy += y_direct[i];

			if (map[bxx][byy] == 'O') {
				bcheck = 1;
				break;
			}
		}

		if (map[rxx][ryy] == '#') {
			rxx -= x_direct[i];
			ryy -= y_direct[i];
		}
		if (map[bxx][byy] == '#') {
			bxx -= x_direct[i];
			byy -= y_direct[i];
		}

		if (rxx == bxx && ryy == byy) {
			if (map[rxx][ryy] == 'O') {
				
			}
			else {
				int px = rx, mx = rx;
				int py = ry, my = ry;
				int find;
				while (1) {
					px += x_direct[i];
					py += y_direct[i];
					mx -= x_direct[i];
					my -= y_direct[i];
					if (px == bx && py == by) {
						find = 1;
						break;
					}
					
					if (mx == bx && my == by) {
						find = 2;
						break;
					}
				}

				if (find == 1) {
					rxx -= x_direct[i];
					ryy -= y_direct[i];
				}
				else {
					bxx -= x_direct[i];
					byy -= y_direct[i];
				}
			}
		}

		if (bcheck && rcheck) {
			bcheck = 0;
			rcheck = 0;
			continue;
		}
		else if (rcheck) {
			ans = cnt + 1;
			break;
		}
		else if (bcheck) {
			bcheck = 0;
			continue;
		}
		if (visit[rxx][ryy][bxx][byy]) continue;

		q.push(make_pair(make_pair(make_pair(rxx, ryy), make_pair(bxx, byy)), cnt + 1));
		visit[rxx][ryy][bxx][byy] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int xr, yr, xb, yb;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'B') {
				xb = i;
				yb = j;
			}
			else if (map[i][j] == 'R') {
				xr = i;
				yr = j;
			}
			else if (map[i][j] == 'O') {
				dx = i;
				dy = j;
			}
		}
	}

	q.push(make_pair(make_pair(make_pair(xr, yr), make_pair(xb, yb)), 0));
	visit[xr][yr][xb][yb] = true;

	while (!q.empty()) {
		int rx = q.front().first.first.first;
		int ry = q.front().first.first.second;
		int bx = q.front().first.second.first;
		int by = q.front().first.second.second;
		int cnt = q.front().second;
		q.pop();

		bfs(rx, ry, bx, by, cnt);

		if (ans != -1) break;
	}

	if (ans > 10) cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}