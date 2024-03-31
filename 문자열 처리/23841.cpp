#include <iostream>
#define MAX 60
using namespace std;

char list[MAX][MAX];
int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (M >> 1); j++) {
			if (list[i][j] != '.') {
				list[i][M - j - 1] = list[i][j];
			}
			else if (list[i][M - j - 1] != '.') {
				list[i][j] = list[i][M - j - 1];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << list[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
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