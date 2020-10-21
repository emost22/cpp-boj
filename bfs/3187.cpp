#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
bool visit[250][250];
char map[250][250];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 }, R, C, K, V;

void bfs() {
	int v = 0, k = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == 'k') k++;
		else if (map[x][y] == 'v') v++;

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= R || yy >= C) continue;
			if (visit[xx][yy] || map[xx][yy] == '#') continue;

			q.push(make_pair(xx, yy));
			visit[xx][yy] = true;
		}
	}

	if (k > v) K += k;
	else V += v;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				q.push(make_pair(i, j));
				visit[i][j] = true;
				bfs();
			}
		}
	}

	cout << K << ' ' << V << '\n';

	return 0;
}