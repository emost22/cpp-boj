#include <iostream>
#include <queue>
#define MAX 51
using namespace std;
typedef pair<pair<int, int>, pair<int, int> > pii;

struct cmp {
	bool operator()(pii a, pii b) {
		return a.second.second > b.second.second;
	}
};

char list[MAX][MAX];
bool visit[MAX][MAX][4][MAX * 2];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, sx, sy, ex, ey;

int bfs() {
	int ans = 1e9;

	priority_queue<pii, vector<pii>, cmp> q;
	q.push({ {sx,sy}, {0,0} });
	q.push({ {sx,sy}, {1,0} });
	q.push({ {sx,sy}, {2,0} });
	q.push({ {sx,sy}, {3,0} });
	visit[sx][sy][0][0] = true;
	visit[sx][sy][1][0] = true;
	visit[sx][sy][2][0] = true;
	visit[sx][sy][3][0] = true;

	while (!q.empty()) {
		int x = q.top().first.first;
		int y = q.top().first.second;
		int d = q.top().second.first;
		int cnt = q.top().second.second;
		q.pop();

		if (x == ex && y == ey) {
			return cnt;
		}

		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (list[nx][ny] == '*') continue;
		if (list[nx][ny] == '!') {
			int nd = (d + 1) % 4;
			if (!visit[nx][ny][nd][cnt + 1]) {
				q.push({ {nx,ny},{nd,cnt + 1} });
				visit[nx][ny][nd][cnt + 1] = true;
			}

			nd = (d + 3) % 4;
			if (!visit[nx][ny][nd][cnt + 1]) {
				q.push({ {nx,ny},{nd,cnt + 1} });
				visit[nx][ny][nd][cnt + 1] = true;
			}
		}

		if (!visit[nx][ny][d][cnt]) {
			q.push({ {nx,ny},{d,cnt} });
			visit[nx][ny][d][cnt] = true;
		}
	}

	return ans;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	bool flag = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < N; j++) {
			if (list[i][j] == '#') {
				!flag ? (sx = i, sy = j): (ex = i, ey = j);
				flag = !flag;
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