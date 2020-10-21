#include <stdio.h>
#include <algorithm>
using namespace std;

char str[26];
int map[26][26], visit[26][26], list[625];
int x_direct[] = { 1,-1,0,0 }, y_direct[] = { 0,0,1,-1 };
int N, sum, cnt;

int dfs(int x, int y) {
	visit[x][y] = 1;
	sum++;

	for (int i = 0; i < 4; i++) {
		int xx = x + x_direct[i];
		int yy = y + y_direct[i];

		if (xx<0 || xx>N || yy<0 || yy>N) continue;
		if (visit[xx][yy] || !map[xx][yy]) continue;
		dfs(xx, yy);
	}

	return sum;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", str);
		for (int j = 1; str[j - 1]; j++) {
			map[i][j] = str[j - 1] - 48;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] && !visit[i][j]) {
				list[cnt++] = dfs(i, j);
				sum = 0;
			}
		}
	}

	sort(list, list + cnt);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", list[i]);
	}

	return 0;
}