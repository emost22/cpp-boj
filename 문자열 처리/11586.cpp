#include <iostream>
using namespace std;

char list[101][101];
int N, K;

void updown() {
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N / 2; i++) {
			list[i][j] = list[i][j] ^ list[N - i - 1][j];
			list[N - i - 1][j] = list[i][j] ^ list[N - i - 1][j];
			list[i][j] = list[i][j] ^ list[N - i - 1][j];
		}
	}
}

void leftright() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N / 2; j++) {
			list[i][j] = list[i][j] ^ list[i][N - j - 1];
			list[i][N - j - 1] = list[i][j] ^ list[i][N - j - 1];
			list[i][j] = list[i][j] ^ list[i][N - j - 1];
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> K;
	if (K == 2) leftright();
	else if (K == 3) updown();
}

void print() {
	for (int i = 0; i < N; i++) {
		cout << list[i] << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	print();

	return 0;
}