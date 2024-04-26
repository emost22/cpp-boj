#include <iostream>
#define MAX 102
using namespace std;

int list[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N;

int getBorder(int x, int y) {
	int ret = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];

		ret += !list[nx][ny];
	}

	return ret;
}

void func() {
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (!list[i][j]) continue;
			ret += getBorder(i, j);
		}
	}
	cout << ret << '\n';
}

void input() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				list[j][k] = 1;
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