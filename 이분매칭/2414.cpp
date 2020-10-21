#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

vector<int> list[2501];
int rownum[MAX][MAX], colnum[MAX][MAX], col[2501];
bool chk[2501];
int N, M, ans, r, c;
char map[MAX][MAX];

void rownumber() {
	int num = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == '*') {
				if (rownum[i][j - 1] == 0) rownum[i][j] = num++;
				else rownum[i][j] = rownum[i][j - 1];
			}
		}
	}

	r = num - 1;
}

void colnumber() {
	int num = 1;
	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			if (map[i][j] == '*') {
				if (colnum[i - 1][j] == 0) colnum[i][j] = num++;
				else colnum[i][j] = colnum[i - 1][j];
			}
		}
	}

	c = num - 1;
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == '*') {
				int row = rownum[i][j];
				int col = colnum[i][j];

				list[row].push_back(col);
			}
		}
	}
}

bool dfs(int x) {
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (chk[y]) continue;
		chk[y] = true;

		if (col[y] == 0 || dfs(col[y])) {
			col[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	rownumber();
	colnumber();
	func();

	for (int i = 1; i <= r; i++) {
		fill(chk, chk + 2501, false);
		if (dfs(i)) ans++;
	}

	cout << ans << '\n';

	return 0;
}