#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200
using namespace std;
typedef pair<int, int> pi;

pi list[2];
bool visit[MAX][MAX];
int direct[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };
int N;

void bfs() {
	queue<pi> q;
	q.push({ list[0] });
	visit[list[0].first][list[0].second] = true;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == list[1].first && y == list[1].second) {
				cout << t << '\n';
				return;
			}

			for (int i = 0; i < 6; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (visit[nx][ny]) continue;

				q.push({ nx,ny });
				visit[nx][ny] = true;
			}
		}
	}

	cout << "-1\n";
	return;
}

void input() {
	cin >> N >> list[0].first >> list[0].second >> list[1].first >> list[1].second;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}