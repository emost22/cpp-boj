#include <iostream>
#define MAX 10
using namespace std;

int list[MAX][MAX];
int ret[MAX * MAX][MAX * MAX];
int N, K;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int x = 0; x < K; x++) {
				for (int y = 0; y < K; y++) {
					ret[i * K + x][j * K + y] = list[i][j];
				}
			}
		}
	}

	for (int i = 0; i < N * K; i++) {
		for (int j = 0; j < N * K; j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
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