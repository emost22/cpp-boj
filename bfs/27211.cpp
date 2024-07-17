#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void bfs(int sx, int sy) {
	queue<pii> q;
	q.push({ sx, sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		auto xy = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = xy.first + direct[d][0];
			int ny = xy.second + direct[d][1];

			if (nx < 0) nx = N - 1;
			if (ny < 0) ny = M - 1;
			if (nx >= N) nx = 0;
			if (ny >= M) ny = 0;
			if (visit[nx][ny] || list[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || list[i][j]) continue;
			ret++;
			bfs(i, j);
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
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