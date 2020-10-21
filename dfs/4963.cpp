#include <iostream>
#include <memory.h>
using namespace std;

int map[50][50], visit[50][50];
int x_direct[] = { -1,-1,-1,0,1,1,1,0 }, y_direct[] = { -1,0,1,1,1,0,-1,-1 };
int width, height, cnt;

int dfs(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 8; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx < 0 || yy < 0 || xx >= height || yy >= width) continue;
		if (visit[xx][yy] || !map[xx][yy]) continue;

		dfs(xx, yy);
	}

	return 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> width >> height;
		if (!width) break;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (!visit[i][j] && map[i][j]) {
					cnt += dfs(i, j);
				}
			}
		}

		cout << cnt << '\n';

		memset(visit, 0, sizeof(visit));
		cnt = 0;
	}

	return 0;
}