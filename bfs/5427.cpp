#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<pair<int, int>, int> > q;
queue<pair<int, int> > f;
bool qvisit[1000][1000], fvisit[1000][1000];
char map[1000][1000];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int h, w, ans = -1;

void fire() {
	int fsize = f.size();
	for (int T = 0; T < fsize; T++) {
		int x = f.front().first;
		int y = f.front().second;
		f.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= h || yy >= w) continue;
			if (fvisit[xx][yy] || map[xx][yy] == '#') continue;

			map[xx][yy] = '*';
			f.push(make_pair(xx, yy));
			fvisit[xx][yy] = true;
		}
	}
}

void bfs() {
	int qsize = q.size();
	for (int T = 0; T < qsize; T++) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= h || yy >= w) {
				ans = cnt + 1;
				return;
			}
			if (qvisit[xx][yy] || map[xx][yy] == '#' || map[xx][yy] == '*') continue;

			q.push(make_pair(make_pair(xx, yy), cnt + 1));
			qvisit[xx][yy] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> map[i];
			for (int j = 0; j < w; j++) {
				if (map[i][j] == '@') {
					q.push(make_pair(make_pair(i, j), 0));
					qvisit[i][j] = true;
				}
				else if (map[i][j] == '*') {
					f.push(make_pair(i, j));
					fvisit[i][j] = true;
				}
			}
		}

		while (!q.empty()) {
			fire();
			bfs();
			if (ans != -1) break;
		}

		if (ans != -1) cout << ans << '\n';
		else cout << "IMPOSSIBLE\n";

		memset(fvisit, false, sizeof(fvisit));
		memset(qvisit, false, sizeof(qvisit));
		while (!q.empty()) q.pop();
		while (!f.empty()) f.pop();
		ans = -1;
	}

	return 0;
}