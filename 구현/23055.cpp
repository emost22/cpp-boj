#include <iostream>
using namespace std;

char list[20][20];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1) list[i][j] = '*';
			else list[i][j] = ' ';
		}
	}

	for (int i = 1, j = 1; i < N - 1; i++, j++) {
		list[i][j] = '*';
	}

	for (int i = N - 2, j = 1; i > 0; i--, j++) {
		list[i][j] = '*';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << list[i][j];
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