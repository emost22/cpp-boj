#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

char list[MAX][MAX];
queue<pii> q[MAX];
bool visit[MAX][MAX];
int dis[MAX];
int ret[MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K;

bool bfs(int idx) {
	int cnt = dis[idx];
	bool flag = false;
	for (int t = 1; t <= cnt && !q[idx].empty(); t++) {
		int qsize = q[idx].size();
		while (qsize--) {
			int x = q[idx].front().first;
			int y = q[idx].front().second;
			q[idx].pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
				if (visit[nx][ny] || list[nx][ny] != '.') continue;

				q[idx].push({ nx,ny });
				visit[nx][ny] = true;
				ret[idx]++;
				flag = true;
			}
		}
	}

	return flag;
}

void func() {
	while (1) {
		bool flag = false;
		for (int i = 1; i <= K; i++) {
			if (q[i].empty()) continue;
			if (bfs(i)) flag = true;
		}

		if (!flag) break;
	}

	for (int i = 1; i <= K; i++) {
		cout << ret[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		cin >> dis[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
			if ('1' <= list[i][j] && list[i][j] <= '9') {
				q[list[i][j] - '0'].push({ i,j });
				visit[i][j] = true;
				ret[list[i][j] - '0']++;
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