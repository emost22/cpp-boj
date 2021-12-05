#include <iostream>
#include <queue>
#define MAX 200
using namespace std;
typedef pair<int, pair<int, int> > pii;

priority_queue<pii> q;
int list[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, S, X, Y;

void func() {
	for (int t = 1; t <= S; t++) {
		priority_queue<pii> nq;
		int qsize = q.size();
		while (qsize--) {
			int x = q.top().second.first;
			int y = q.top().second.second;
			int type = -q.top().first;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + direct[i][0];
				int ny = y + direct[i][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if (list[nx][ny]) continue;

				list[nx][ny] = type;
				nq.push({ -type, {nx,ny} });
			}
		}
		q = nq;
	}

	cout << list[X - 1][Y - 1] << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
			if (list[i][j] > 0) {
				q.push({ -list[i][j], {i,j} });
			}
		}
	}
	cin >> S >> X >> Y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}