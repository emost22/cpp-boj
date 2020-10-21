#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

queue<pair<int, int> > q;
vector<pair<int, int> > v;
bool visit[101][101];
char map[101][101];
int direct[4][4] = { {0,1},{1,0},{0,-1},{-1,0} };
int R, C, N;

bool bfs() {
	int bottom = R;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		v.push_back({ x,y });
		bottom = min(bottom, x);
		if (bottom == 1) {
			while (!q.empty()) q.pop();
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nextx = x + direct[i][0];
			int nexty = y + direct[i][1];

			if (visit[nextx][nexty] || map[nextx][nexty] == '.') continue;
			if (nextx <= 0 || nexty <= 0 || nextx > R || nexty > C) continue;

			q.push({ nextx, nexty });
			visit[nextx][nexty] = true;
		}
	}

	return false;
}

void cmove(int d) {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		map[x][y] = '.';
		map[x - d][y] = 'x';
	}
}

void delm(int h, bool turn) {
	int w;
	if (turn) {
		for (int i = 1; i <= C; i++) {
			if (map[h][i] == '.') continue;

			map[h][i] = '.';
			w = i;
			break;
		}
	}
	else {
		for (int i = C; i >= 1; i--) {
			if (map[h][i] == '.') continue;

			map[h][i] = '.';
			w = i;
			break;
		}
	}

	for (int i = 0; i < 4; i++) {
		int nextx = h + direct[i][0];
		int nexty = w + direct[i][1];

		if (map[nextx][nexty] == 'x') {
			memset(visit, false, sizeof(visit));
			q.push({ nextx, nexty });
			visit[nextx][nexty] = true;
			if (bfs()) {
				v.clear();
				continue;
			}

			int fall = R;
			bool chk = false;
			for (int j = 0; j < v.size(); j++) {
				int x = v[j].first;
				int y = v[j].second;

				int maxh = x;
				for (int k = x - 1; k >= 1; k--) {
					if (visit[k][y]) {
						chk = true;
						break;
					}
					if (map[k][y] == '.') {
						if (k == 1) maxh = 0;
						continue;
					}
					maxh = k;
					break;
				}

				if (!chk) fall = min(fall, x - maxh - 1);
				chk = false;
			}

			cmove(fall);
			v.clear();
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	bool turn = true;
	int x;
	cin >> R >> C;
	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}

	cin >> N;
	while (N--) {
		cin >> x;
		
		delm(x, turn);
		turn = !turn;
	}

	for (int i = R; i >= 1; i--) {
		for (int j = 1; j <= C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}