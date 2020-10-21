#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, pair<int, int> > > q;
char map[1010][1010];
bool visit[1010][1010][2];
int x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 }, N, M, ans = -1;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int broken = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int xx = x + x_direct[i];
			int yy = y + y_direct[i];

			if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
			if (map[xx][yy] == '1' && broken == 1) continue;

			if (map[xx][yy] == '1' && !visit[xx][yy][broken + 1]) {
				q.push(make_pair(make_pair(xx, yy), make_pair(cnt + 1, broken + 1)));
				visit[xx][yy][broken + 1] = true;
			}
			else if(map[xx][yy]=='0' && !visit[xx][yy][broken]){
				q.push(make_pair(make_pair(xx, yy), make_pair(cnt + 1, broken)));
				visit[xx][yy][broken] = true;
			}

			
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	q.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
	visit[0][0][0] = true;
	bfs();

	cout << ans << '\n';

	return 0;
}