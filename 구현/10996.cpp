#include <iostream>
using namespace std;

char list[200][100];

void init() {
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 100; j++) {
			if ((i + j) % 2) list[i][j] = ' ';
			else list[i][j] = '*';
		}
	}
}

void input() {
	int N;
	cin >> N;
	if (N == 1) cout << "*\n";
	else {
		for (int i = 0; i < N * 2; i++) {
			for (int j = 0; j < N; j++) {
				cout << list[i][j];
			}
			cout << '\n';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}