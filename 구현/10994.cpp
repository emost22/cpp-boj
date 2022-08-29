#include <iostream>
#define MAX 101
using namespace std;

char list[MAX * 4][MAX * 4];
int N;

void func() {
	int x = 1;
	int y = 1;
	int sz = 1 + (N - 1) * 4;
	N = sz;
	while (x <= sz) {
		for (int i = x; i <= sz; i++) {
			list[i][y] = '*';
			list[i][N - y + 1] = '*';
		}
		for (int j = y; j <= sz; j++) {
			list[x][j] = '*';
			list[N - x + 1][j] = '*';
		}
		x += 2;
		y += 2;
		sz -= 2;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (list[i][j]) cout << list[i][j];
			else cout << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}