#include <iostream>
using namespace std;

char list[101][201];
int N;

void func() {
	int x = N;
	int y = 1;
	bool chk = true;
	for (; y <= N * 2 - 1; y++) {
		list[x][y] = '*';

		if (x == 1) chk = !chk;

		if (chk) x--;
		else x++;
	}

	y = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= y; j++) {
			cout << list[i][j];
		}
		y++;
		cout << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N * 2 - 1; j++) {
			list[i][j] = ' ';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}