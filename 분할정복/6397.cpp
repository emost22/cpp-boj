#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int map[200][200], cnt, ccnt, a, b;
char ch;

void div(int xsize, int ysize, int sx, int sy, int ex, int ey) {
	if (sx > ex || sy > ey) return;
	int check = map[sx][sy], ans;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (check != map[i][j]) {
				ans = 1;
				break;
			}
			else ans = 0;
		}
		if (ans) break;
	}

	if (ans) {
		printf("D");
		cnt++;
		if (cnt == 50) {
			cnt = 0;
			printf("\n");
		}
		if (xsize % 2 && ysize % 2) {
			div(xsize / 2 + 1, ysize / 2 + 1, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div(xsize / 2 + 1, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div(xsize / 2, ysize / 2 + 1, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		else if (xsize % 2) {
			div(xsize / 2 + 1, ysize / 2, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div(xsize / 2 + 1, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		else if (ysize % 2) {
			div(xsize / 2, ysize / 2 + 1, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div(xsize / 2, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div(xsize / 2, ysize / 2 + 1, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		else {
			div(xsize / 2, ysize / 2, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div(xsize / 2, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
	}
	else {
		printf("%d", check);
		cnt++;
		if (cnt == 50) {
			cnt = 0;
			printf("\n");
		}
	}
}

void div2(int xsize, int ysize, int sx, int sy, int ex, int ey) {
	if (sx > ex || sy > ey) return;
	if (ch == '1' || ch == '0') {
		for (int i = sx; i <= ex; i++) {
			for (int j = sy; j <= ey; j++) {
				map[i][j] = ch - 48;
				if (i == a - 1 && j == b - 1) return;
			}
		}
		scanf("%c", &ch);
		ccnt++;
		if (ccnt == 50) {
			ccnt = 0;
			getchar();
		}
	}
	else if (ch == 'D') {
		scanf("%c", &ch);
		ccnt++;
		if (ccnt == 50) {
			ccnt = 0;
			getchar();
		}
		if (xsize % 2 && ysize % 2) {
			div2(xsize / 2 + 1, ysize / 2 + 1, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div2(xsize / 2 + 1, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div2(xsize / 2, ysize / 2 + 1, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div2(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		else if (xsize % 2) {
			div2(xsize / 2 + 1, ysize / 2, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div2(xsize / 2 + 1, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div2(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div2(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		else if (ysize % 2) {
			div2(xsize / 2, ysize / 2 + 1, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div2(xsize / 2, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div2(xsize / 2, ysize / 2 + 1, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div2(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
		else {
			div2(xsize / 2, ysize / 2, sx, sy, (sx + ex) / 2, (sy + ey) / 2);
			div2(xsize / 2, ysize / 2, sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey);
			div2(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2);
			div2(xsize / 2, ysize / 2, (sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey);
		}
	}
}

int main() {
	char type;
	while (1) {
		scanf("%c", &type);
		if (type == '#') break;

		scanf("%d %d", &a, &b);
		if (type == 'B') {
			printf("D %3d %3d\n", a, b);
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					scanf("%1d", &map[i][j]);
				}
			}
			div(a, b, 0, 0, a - 1, b - 1);
			getchar();
		}
		else if (type == 'D') {
			printf("B %3d %3d\n", a, b);
			getchar();
			scanf("%c", &ch);
			ccnt++;
			div2(a, b, 0, 0, a - 1, b - 1);
			cnt = 0;
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					printf("%d", map[i][j]);
					cnt++;
					if (cnt == 50) {
						cnt = 0;
						printf("\n");
					}
				}
			}
			ccnt = 0;
			getchar();
		}
		if (cnt) printf("\n");
		cnt = 0;
	}

	return 0;
}