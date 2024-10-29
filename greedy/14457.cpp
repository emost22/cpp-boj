#include <iostream>
#define MAX 11
using namespace std;

char list[MAX][MAX];
int N;

void reverseMatrix(int x, int y) {
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (list[i][j] == '0') list[i][j] = '1';
			else list[i][j] = '0';
		}
	}
}

void func() {
	int ret = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (list[i][j] == '0') continue;

			ret++;
			reverseMatrix(i, j);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}