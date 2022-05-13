#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<int> sizeList;
int N, M;

void bfs(int sx, int sy, int num) {
	int ret = 0;
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		ret++;
		list[x][y] = num;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	sizeList.push_back(ret);
}

void func() {
	sizeList.push_back(0);
	int num = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j] || visit[i][j]) continue;

			bfs(i, j, num++);
		}
	}

	int ans = 0;
	set<int> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j]) continue;

			int ret = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (!list[nx][ny]) continue;
				if (s.find(list[nx][ny]) != s.end()) continue;

				s.insert(list[nx][ny]);
				ret += sizeList[list[nx][ny]];
			}

			ans = max(ans, ret + 1);
			s.clear();
		}
	}

	cout << ans << '\n';
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