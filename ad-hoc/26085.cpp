#include <iostream>
#define MAX 1001
using namespace std;

int list[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, z, o;

bool isErase(int x, int y) {
	for (int d = 0; d < 4; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (list[x][y] == list[nx][ny]) return true;
	}
	return false;
}

void func() {
	if (o & 1 || z & 1) {
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isErase(i, j)) {
				cout << "1\n";
				return;
			}
		}
	}
	cout << "-1\n";
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			list[i][j] & 1 ? o++ : z++;
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