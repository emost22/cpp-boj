#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 102
using namespace std;
typedef pair<int, int> pi;

char list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, key, ans;

bool bfs() {
	bool flag = false;
	memset(visit, false, sizeof(visit));
	queue<pi> q;
	q.push({ 0,0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx > N + 1 || ny > M + 1) continue;
			if (list[nx][ny]=='*' || visit[nx][ny]) continue;
			if ('A' <= list[nx][ny] && list[nx][ny] <= 'Z') {
				int k = 1 << (list[nx][ny] - 'A');
				if (!(key & k)) continue;

				flag = true;
			}
			else if ('a' <= list[nx][ny] && list[nx][ny] <= 'z') {
				int k = 1 << (list[nx][ny] - 'a');
				key |= k;

				flag = true;
			}
			else if (list[nx][ny] == '$') ans++;

			list[nx][ny] = '.';
			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	return flag;
}

void func() {
	while (bfs());

	cout << ans << '\n';
}

void input() {
	string str;
	cin >> N >> M;
	for (int i = 0; i < N + 2; i++) {
		list[i][0] = '.';
		list[i][M + 1] = '.';
	}

	for (int i = 0; i < M + 2; i++) {
		list[0][i] = '.';
		list[N + 1][i] = '.';
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
	cin >> str;
	if (str == "0") return;

	for (int i = 0; i < str.size(); i++) {
		int k = 1 << (str[i] - 'a');

		key |= k;
	}
}

void init() {
	key = 0;
	ans = 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}