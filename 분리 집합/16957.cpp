#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 501
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX], ans[MAX][MAX];
pi parent[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int N, M;

pi find(pi xy) {
	if (parent[xy.first][xy.second] == xy) return xy;
	else return parent[xy.first][xy.second] = find(parent[xy.first][xy.second]);
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x = i;
			int y = j;
			for (int k = 0; k < 8; k++) {
				int nx = i + direct[k][0];
				int ny = j + direct[k][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

				if (list[x][y] > list[nx][ny]) {
					x = nx;
					y = ny;
				}
			}

			parent[i][j] = { x,y };
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pi xy = find(parent[i][j]);

			ans[xy.first][xy.second]++;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
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