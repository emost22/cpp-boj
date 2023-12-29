#include <iostream>
#define MAX 101
using namespace std;

char list[MAX][MAX];
int N, M;

void reverseCoin(int ex, int ey) {
	for (int i = 0; i <= ex; i++) {
		for (int j = 0; j <= ey; j++) {
			list[i][j] = list[i][j] == '0' ? '1' : '0';
		}
	}
}

void func() {
	int ret = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (list[i][j] == '0') continue;
			ret++;
			reverseCoin(i, j);
		}
	}

	cout << ret << '\n';
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