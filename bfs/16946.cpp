#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define MAX 1001
#define MOD 10
using namespace std;
typedef pair<int, int> pi;

char list[MAX][MAX];
bool visit[MAX][MAX];
int num[MAX][MAX], ans[MAX][MAX];
int numSize[MAX * MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

void func() {
	set<int> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] == '0') continue;

			int sum = 0;
			for (int d = 0; d < 4; d++) {
				int nx = i + direct[d][0];
				int ny = j + direct[d][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (list[nx][ny] != '0') continue;
				if (s.find(num[nx][ny]) != s.end()) continue;

				sum += numSize[num[nx][ny]];
				s.insert(num[nx][ny]);
			}

			ans[i][j] = (sum + 1) % MOD;
			s.clear();
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}

void bfs(int sx, int sy, int n) {
	queue<pi> q;
	q.push({ sx,sy });
	visit[sx][sy] = true;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		cnt++;
		num[x][y] = n;
		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (visit[nx][ny] || list[nx][ny] == '1') continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	numSize[n] = cnt;
}

void init() {
	int n = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || list[i][j] == '1') continue;

			bfs(i, j, n++);
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}