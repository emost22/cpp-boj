#include <iostream>
using namespace std;

char list[101][201];
int N;

void print() {
	for (int i = 1; i <= N; i++) {
		int M = N * 2;
		if (i % 2) M--;
		for (int j = 1; j <= M; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N * 2; j++) {
			if (i % 2) {
				if (j % 2) list[i][j] = '*';
				else list[i][j] = ' ';
			}
			else {
				if (j % 2) list[i][j] = ' ';
				else list[i][j] = '*';
			}
		}
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
	print();

	return 0;
}