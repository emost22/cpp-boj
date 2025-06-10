#include <iostream>
#include <cstring>
#define MAX 10
using namespace std;

int list[MAX][MAX];
int col[MAX], row[MAX], area[MAX];

int getAreaIdx(int x, int y) {
	return x / 3 * 3 + y / 3;
}

void func(int tc) {
	cout << "Case " << tc << ": ";
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			int idx = getAreaIdx(i, j);
			if (row[i] & (1 << list[i][j]) || col[j] & (1 << list[i][j]) || area[idx] & (1 << list[i][j])) {
				cout << "INCORRECT\n";
				return;
			}

			row[i] |= (1 << list[i][j]);
			col[j] |= (1 << list[i][j]);
			area[idx] |= (1 << list[i][j]);
		}
	}

	cout << "CORRECT\n";
}

void input() {
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			cin >> list[i][j];
		}
	}
}

void init() {
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	memset(area, 0, sizeof(area));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
		init();
	}

	return 0;
}