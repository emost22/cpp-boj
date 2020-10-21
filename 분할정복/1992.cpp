#include <iostream>
#include <cstdio>
using namespace std;

int map[64][64];

void div(int N, int x, int y) {
	int ans = 0, check = map[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j] != check) {
				ans = 1;
				break;
			}
		}
		if (ans) break;
	}

	if (!ans) {
		printf("%d", check);
	}
	else {
		if (N != 1) {
			printf("(");
			div(N / 2, x, y);
			div(N / 2, x, y + N / 2);
			div(N / 2, x + N / 2, y);
			div(N / 2, x + N / 2, y + N / 2);
			printf(")");
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	div(N, 0, 0);
	printf("\n");

	return 0;
}