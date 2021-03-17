#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int> > q;
int list[21][21];
bool visit[21][21];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second < b.second) return true;
		else return false;
	}
	else return false;
}

void bfs() {
	int ssize = 2;
	int eat = 0;
	while (1) {
		bool chk = false;
		vector<pair<int, int> > v;
		for (int t = 1; ; t++) {
			int qsize = q.size();
			while (qsize--) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + direct[i][0];
					int ny = y + direct[i][1];

					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visit[nx][ny]) continue;
					if (list[nx][ny] > ssize) continue;

					if (list[nx][ny] && list[nx][ny] < ssize) {
						v.push_back({ nx,ny });
					}
					q.push({ nx,ny });
					visit[nx][ny] = true;
				}
			}

			if (!v.empty()) {
				ans += t;
				break;
			}
			if (q.empty()) {
				chk = true;
				break;
			}
		}
		if (chk) break;

		sort(v.begin(), v.end(), cmp);
		int x = v[0].first;
		int y = v[0].second;
		list[x][y] = 0;
		eat++;
		if (eat == ssize) {
			ssize++;
			eat = 0;
		}
		v.clear();
		memset(visit, false, sizeof(visit));
		while (!q.empty()) q.pop();
		q.push({ x,y });
		visit[x][y] = true;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
			if (list[i][j] == 9) {
				q.push({ i,j });
				visit[i][j] = true;
				list[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}