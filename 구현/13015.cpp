#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

char list[MAX << 1][MAX << 2];
int N;

void func() {
	int x = (N << 1) - 1;
	int y = N * 3 + N - 3;
	memset(list, ' ', sizeof(list));
	for (int i = 0; i < N; i++) {
		list[0][i] = '*';
		list[0][i + (N << 1) + N - 3] = '*';
		list[x - 1][i] = '*';
		list[x - 1][i + (N << 1) + N - 3] = '*';
	}

	for (int i = 0; i < N; i++) {
		list[i][i] = '*';
		list[i][i + N - 1] = '*';
		list[i][y - 1 - i] = '*';
		list[i][y - N - i] = '*';
	}

	for (int i = 0; i < N; i++) {
		list[x - 1 - i][i] = '*';
		list[x - 1 - i][i + N - 1] = '*';
		list[x - 1 - i][y - 1 - i] = '*';
		list[x - 1 - i][y - N - i] = '*';
	}

	int py = y + 1;
	for (int i = 0; i < x; i++) {
		if (i < N) py--;
		else py++;

		for (int j = 0; j < py; j++) {
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