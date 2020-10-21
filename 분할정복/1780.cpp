#include <iostream>
using namespace std;

int map[2187][2187], ans[3];

void find(int N, int x, int y) {
	int check = 0;
	int num = map[x][y];
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j] != num) {
				check = 1;
				break;
			}
		}
		if (check) break;
	}
	if (!check) ans[num + 1]++;
	else if (N != 1) {
		find(N / 3, x, y);
		find(N / 3, x + N / 3, y);
		find(N / 3, x + N * 2 / 3, y);
		find(N / 3, x, y + N / 3);
		find(N / 3, x + N / 3, y + N / 3);
		find(N / 3, x + N * 2 / 3, y + N / 3);
		find(N / 3, x, y + N * 2 / 3);
		find(N / 3, x + N / 3, y + N * 2 / 3);
		find(N / 3, x + N * 2 / 3, y + N * 2 / 3);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	find(N, 0, 0);

	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';

	return 0;
}