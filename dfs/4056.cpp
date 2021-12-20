#include <iostream>
#include <cstring>
#define MAX 10
#define N 9
using namespace std;

int area[N][N] = { 
	{0, 0, 0, 1, 1, 1, 2, 2, 2},
	{0, 0, 0, 1, 1, 1, 2, 2, 2},
	{0, 0, 0, 1, 1, 1, 2, 2, 2},
	{3, 3, 3, 4, 4, 4, 5, 5, 5},
	{3, 3, 3, 4, 4, 4, 5, 5, 5},
	{3, 3, 3, 4, 4, 4, 5, 5, 5},
	{6, 6, 6, 7, 7, 7, 8, 8, 8},
	{6, 6, 6, 7, 7, 7, 8, 8, 8},
	{6, 6, 6, 7, 7, 7, 8, 8, 8}
};
int list[N][N];
bool row[N][MAX], col[N][MAX], areaChk[N][MAX];
bool f;

bool dfs(int now) {
	if (now == N * N) return true;

	int x = now / 10;
	int y = now % 10;
	if (list[x][y] != 0) return dfs(now + 1);

	for (int i = 1; i <= N; i++) {
		if (row[x][i] || col[y][i] || areaChk[area[x][y]][i]) continue;

		row[x][i] = true;
		col[y][i] = true;
		areaChk[area[x][y]][i] = true;
		list[x][y] = i;
		
		bool flag = dfs(now + 1);
		if (flag) return flag;

		list[x][y] = 0;
		row[x][i] = false;
		col[y][i] = false;
		areaChk[area[x][y]][i] = false;
	}

	return false;
}

void func() {
	if (f) {
		cout << "Could not complete this grid.\n";
		return;
	}

	if (dfs(0)) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << list[i][j];
			}
			cout << '\n';
		}
	}
	else cout << "Could not complete this grid.\n";
}

void input() {
	char x;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;

			list[i][j] = x - '0';

			if (!list[i][j]) continue;

			if (row[i][list[i][j]] || col[j][list[i][j]] || areaChk[area[i][j]][list[i][j]]) {
				f = true;
			}

			row[i][list[i][j]] = true;
			col[j][list[i][j]] = true;
			areaChk[area[i][j]][list[i][j]] = true;
		}
	}
}

void init() {
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	memset(areaChk, false, sizeof(areaChk));
	f = false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		init();
		input();
		func();
		if (tc) cout << '\n';
	}

	return 0;
}