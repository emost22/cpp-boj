#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 2001
using namespace std;
typedef pair<int, int> pii;

queue<pii> q, mq;
vector<pii> v;
int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, K;

void func() {
	visit[q.front().first][q.front().second] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (list[x][y] == 2) {
				cout << t << '\n';
				return;
			}

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny] || list[nx][ny] == 1) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
	cout << "-1\n";
}

void cantMove() {
	for (int t = 1; !mq.empty() && t <= K; t++) {
		int qsize = mq.size();
		while (qsize--) {
			int x = mq.front().first;
			int y = mq.front().second;
			mq.pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + direct[d][0];
				int ny = y + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny]) continue;

				mq.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (list[i][j] == 4) {
				q.push({ i,j });
			}
			else if (list[i][j] == 3) {
				mq.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	cantMove();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}