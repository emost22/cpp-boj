#include <iostream>
using namespace std;

char zone[9][9] = { 
	{ 'a','a','a','b','b','b','c','c','c' },
	{ 'a','a','a','b','b','b','c','c','c' },
	{ 'a','a','a','b','b','b','c','c','c' },
	{ 'd','d','d','e','e','e','f','f','f' },
	{ 'd','d','d','e','e','e','f','f','f' },
	{ 'd','d','d','e','e','e','f','f','f' },
	{ 'g','g','g','h','h','h','i','i','i' },
	{ 'g','g','g','h','h','h','i','i','i' },
	{ 'g','g','g','h','h','h','i','i','i' }
};
int map[9][9], ans;
bool width[9][10], height[9][10], area[9][10];

void dfs(int x, int y, int cnt) {
	if (cnt == 81) {
		ans = 1;
		return;
	}

	if (map[x][y]) {
		if (y == 8) dfs(x + 1, 0, cnt + 1);
		else dfs(x, y + 1, cnt + 1);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (!width[x][i] && !height[y][i] && !area[zone[x][y] - 97][i]) {
			map[x][y] = i;
			width[x][i] = true;
			height[y][i] = true;
			area[zone[x][y] - 97][i] = true;
			if (y == 8) dfs(x + 1, 0, cnt + 1);
			else dfs(x, y + 1, cnt + 1);
			if (ans) return;
			map[x][y] = 0;
			width[x][i] = false;
			height[y][i] = false;
			area[zone[x][y] - 97][i] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			width[i][map[i][j]] = true;
			height[j][map[i][j]] = true;
			area[zone[i][j] - 97][map[i][j]] = true;
		}
	}

	dfs(0, 0, 0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}