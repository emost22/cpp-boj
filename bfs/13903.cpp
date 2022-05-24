#include <iostream>
#include <queue>
#define MAX 1001
#define R 11
using namespace std;
typedef pair<int, int> pii;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[R][2];
int N, M, K;

int bfs() {
	queue<pii> q;
	for (int i = 0; i < M; i++) {
		if (list[0][i]) {
			q.push({ 0,i });
			visit[0][i] = true;
		}
	}

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == N - 1) return t;

			for (int i = 0; i < K; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny] || !list[nx][ny]) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> direct[i][0] >> direct[i][1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}