#include <iostream>
#define MAX 110
using namespace std;

char ret[MAX][MAX];
int N, M, A, B;

void func() {
	for (int i = 0; i < N * A; i += A) {
		for (int j = 0; j < M * B; j += B) {
			char tmp = 'X';
			if ((i / A + j / B) & 1) tmp = '.';

			for (int x = 0; x < A; x++) {
				for (int y = 0; y < B; y++) {
					ret[i + x][j + y] = tmp;
				}
			}
		}
	}

	for (int i = 0; i < N * A; i++) {
		for (int j = 0; j < M * B; j++) {
			cout << ret[i][j];
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M >> A >> B;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}