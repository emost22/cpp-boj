#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 60
using namespace std;
typedef pair<int, int> pii;

int list[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;
int maxHeight;

void bfs(int h) {
	queue<pii> q;
	q.push({ 0,0 });
	list[0][0] = h;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + direct[d][0];
			int ny = y + direct[d][1];

			if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;
			if (list[nx][ny] >= h) continue;

			list[nx][ny] = h;
			q.push({ nx,ny });
		}
	}
}

void func() {
	int ret = 0;
	for (int h = 1; h <= maxHeight; h++) {
		bfs(h);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (list[i][j] >= h) continue;
				ret++;
				list[i][j] = h;
			}
		}
	}
	cout << ret << '\n';
}

void input() {
	char x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x;
			list[i][j] = x - '0';
			maxHeight = max(maxHeight, list[i][j]);
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