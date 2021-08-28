#include <iostream>
using namespace std;

char list[101][201];
int N;

void func() {
	int x = N;
	int y = 1;

	bool chk = false;
	for (; y <= N * 2 - 1; y++) {
		list[x][y] = '*';
		
		if (x == 1) chk = !chk;

		if (!chk) x--;
		else x++;
	}

	int e = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= e; j++) {
			if (i == N) cout << '*';
			else cout << list[i][j];
		}
		cout << '\n';
		e++;
	}
}

void input() {
	cin >> N;
	int e = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= e; j++) {
			list[i][j] = ' ';
		}
		e++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}