#include <iostream>
#define MAX 51
using namespace std;

int N, M, x, y;

void func() {
	int list[MAX][MAX] = { 0, };
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i - x >= 0 && j - y >= 0 && list[i - x][j - y]) continue;
			list[i][j] = 1;
			ret++;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}