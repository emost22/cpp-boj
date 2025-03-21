#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;

char list[MAX][MAX];
bool chk[MAX][MAX];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M;

bool isInRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}

bool isBetweenWater(int x, int y) {
	int cnt = 0;
	for (int d = 0; d < 4; d++) {
		int nx = x + direct[d][0];
		int ny = y + direct[d][1];
		if (isInRange(nx, ny)) cnt += (list[nx][ny] == '.');
		else cnt++;
	}
	return cnt >= 3;
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] == '.') continue;
			chk[i][j] = isBetweenWater(i, j);
		}
	}

	int mnx = MAX;
	int mxx = 0;
	int mny = MAX;
	int mxy = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (chk[i][j]) list[i][j] = '.';
			if (list[i][j] == 'X') {
				mnx = min(mnx, i);
				mxx = max(mxx, i);
				mny = min(mny, j);
				mxy = max(mxy, j);
			}
		}
	}

	for (int i = mnx; i <= mxx; i++) {
		for (int j = mny; j <= mxy; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}