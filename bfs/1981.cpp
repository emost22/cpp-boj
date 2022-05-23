#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N;

bool bfs(int l, int r) {
	if (list[0][0] < l || list[0][0] > r) return false;

	memset(visit, false, sizeof(visit));
	queue<pi> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == N - 1 && y == N - 1) return true;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visit[nx][ny]) continue;
			if (list[nx][ny] < l || list[nx][ny] > r) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	return false;
}

void func() {
	int l = 0;
	int r = 0;
	int ans = 1e9;
	while (r <= 200) {
		if (bfs(l, r)) {
			ans = min(ans, r - l);
			l++;
		}
		else r++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
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