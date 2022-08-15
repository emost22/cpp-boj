#include <iostream>
#define MAX 101
using namespace std;

int matrix1[MAX][MAX], matrix2[MAX][MAX];
int N, M, K;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int ans = 0;
			for (int k = 0; k < M; k++) {
				ans += (matrix1[i][k] * matrix2[k][j]);
			}
			cout << ans << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix1[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> matrix2[i][j];
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