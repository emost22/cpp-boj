#include <iostream>
#define MAX 100
using namespace std;

int list[MAX][MAX];
int N, M;

void func() {
	int ret = N * M;
	for (int i = 0; i < N; i++) {
		ret += list[i][0];
		for (int j = 1; j < M; j++) {
			if (list[i][j] <= list[i][j - 1]) continue;

			ret += (list[i][j] - list[i][j - 1]);
		}
	}

	for (int j = 0; j < M; j++) {
		ret += list[0][j];
		for (int i = 1; i < N; i++) {
			if (list[i][j] <= list[i - 1][j]) continue;

			ret += (list[i][j] - list[i - 1][j]);
		}
	}

	cout << (ret << 1) << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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