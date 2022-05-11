#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K;

void bfs(int sx, int sy) {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j] || visit[i][j]) continue;
			bfs(i, j);
			ans++;
		}
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] < K) list[i][j] = 0;
			else list[i][j] = 255;
		}
	}
}

void input() {
	int x, y, z;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> x >> y >> z;
			list[i][j] = x + y + z;
		}
	}
	cin >> K;
	K *= 3;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}