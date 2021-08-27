#include <iostream>
using namespace std;

char list[101][201];
int N;

void func() {
	int s = N;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = s; j <= N * 2 - 1; j++) {
			if (!cnt) list[i][j] = '*';

			cnt = 1 - cnt;
		}
		s--;
	}

	s = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= s; j++) {
			cout << list[i][j];
		}
		cout << '\n';
		s++;
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