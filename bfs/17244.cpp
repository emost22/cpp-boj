#include <iostream>
#include <queue>
#define MAX 50
using namespace std;
typedef pair<pair<int, int>, int> pii;

queue<pii> q;
char list[MAX][MAX];
bool visit[MAX][MAX][1 << 5];
int chk[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, bit;
int ds, de;

void bfs() {
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];
				int ncnt = cnt;

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
				if (list[nx][ny] == 'X') {
					int b = chk[nx][ny];

					ncnt |= b;
				}
				if (list[nx][ny] == '#' || visit[nx][ny][ncnt]) continue;

				if (list[nx][ny] == 'E' && ncnt == bit) {
					cout << t << '\n';
					return;
				}

				q.push({ {nx,ny}, ncnt });
				visit[nx][ny][ncnt] = true;
			}
		}
	}
}

void input() {
	int cnt = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (list[i][j] == 'S') {
				q.push({ {i,j},0 });
				visit[i][j][0] = true;
			}
			else if (list[i][j] == 'E') {
				ds = i;
				de = j;
			}
			else if (list[i][j] == 'X') {
				chk[i][j] = (1 << cnt);
				cnt++;
			}
		}
	}

	bit = (1 << cnt) - 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}