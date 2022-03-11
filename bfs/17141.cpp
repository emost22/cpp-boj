#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 50
using namespace std;
typedef pair<int, int> pi;

vector<pi> virus, tmp;
int list[MAX][MAX];
bool visit[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, virusCnt, ans;

bool allChk() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (list[i][j] != 1 && !visit[i][j]) return false;
		}
	}

	return true;
}

int bfs() {
	queue<pi> q;
	memset(visit, false, sizeof(visit));
	for (int i = 0; i < M; i++) {
		q.push({ tmp[i] });
		visit[tmp[i].first][tmp[i].second] = true;
	}
	int t = 0;
	for (; ; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (list[nx][ny] == 1 || visit[nx][ny]) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}

		if (q.empty()) {
			if (allChk()) return t;
			else return 1e9;
		}
	}
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		ans = min(ans, bfs());
		return;
	}

	for (int i = idx; i < virusCnt; i++) {
		tmp.push_back(virus[i]);
		dfs(i + 1, cnt + 1);
		tmp.pop_back();
	}
}

void func() {
	ans = 1e9;
	dfs(0, 0);

	if (ans == 1e9) cout << "-1\n";
	else cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
			if (list[i][j] == 2) {
				virus.push_back({ i,j });
				virusCnt++;
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