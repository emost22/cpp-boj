#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool visit[1001][1001];
int list[1001][1001];
int N, M, ans;

void bfs() {
	int t = 1;
	for (; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];
				
				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (visit[nx][ny] || list[nx][ny] == -1) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
				ans--;
			}
		}

		if (!ans) {
			cout << t << '\n';
			return;
		}
	}

	cout << "-1\n";
}

void func() {
	if (!ans) {
		cout << "0\n";
		return;
	}

	bfs();
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (!list[i][j])
				ans++;
			else if (list[i][j] == 1) {
				q.push({ i,j });
				visit[i][j] = true;
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