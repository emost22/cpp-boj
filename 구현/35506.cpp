#include <iostream>
#define MAX 410
using namespace std;

char ret[MAX][MAX];
int N;

void func() {
	int i = (N << 1) - 1;
	int j = 0;
	while (i >= 0 && j < (N << 1)) {
		ret[i--][j++] = '*';
	}

	i = N - 1;
	j = (N << 1) + 1;
	int k = (N << 2) + 1;
	while (i >= 0 && j < N * 3 + 1 && k > N * 3 + 1) {
		ret[i][j++] = '*';
		ret[i--][k--] = '*';
	}

	i = N;
	j = (N << 1) + 1;
	k = (N << 2) + 1;
	while (i < (N << 1) && j < N * 3 + 1 && k > N * 3 + 1) {
		ret[i][j++] = '*';
		ret[i++][k--] = '*';
	}

	for (int i = 0; i < (N << 1); i++) {
		for (int j = 0; j < (N << 2) + 2; j++) {
			if (!ret[i][j]) cout << ' ';
			else cout << ret[i][j];
		}
		cout << '\n';
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

	return 0;
}