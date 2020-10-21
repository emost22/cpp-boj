#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int> > s;
queue<pair<int, int> > water;
char map[50][50];
bool wvisit[50][50], svisit[50][50];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int R, C, ans = -1;

void sec() {
	int wsize = water.size();
	for (int T = 0; T < wsize; T++) {
		int x = water.front().first;
		int y = water.front().second;
		int cnt = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= R || yy >= C) continue;
			if (wvisit[xx][yy] || map[xx][yy] == 'D' || map[xx][yy] == 'X') continue;

			map[xx][yy] = '*';

			water.push(make_pair(xx, yy));
			wvisit[xx][yy] = true;
		}
	}
}

void bfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= R || yy >= C) continue;
		if (svisit[xx][yy] || map[xx][yy] == '*' || map[xx][yy] == 'X') continue;

		if (map[xx][yy] == 'D') {
			ans = cnt + 1;
			break;
		}
		s.push(make_pair(make_pair(xx, yy), cnt + 1));
		svisit[xx][yy] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') {
				s.push(make_pair(make_pair(i, j), 0));
				svisit[i][j] = true;
			}
			else if (map[i][j] == '*') {
				water.push(make_pair(i, j));
				wvisit[i][j] = true;
			}
		}
	}

	while (!s.empty()) {
		sec();

		int ssize = s.size();
		
		for (int T = 0; T < ssize; T++) {
			int x = s.front().first.first;
			int y = s.front().first.second;
			int cnt = s.front().second;
			s.pop();

			bfs(x, y, cnt);
		}
		if (ans != -1) break;
	}

	if (ans != -1) cout << ans << '\n';
	else cout << "KAKTUS\n";

	return 0;
}