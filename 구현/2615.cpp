#include <iostream>
using namespace std;

int direct[4][2] = { {-1,1}, {0,1},{1,1},{1,0} };
int list[21][21];

bool solve1() {
	int idx = 0;
	for (int i = 5; i <= 19; i++) {
		for (int j = 1; j <= 15; j++) {
			if (!list[i][j]) continue;

			int cnt = 1;
			int nx = i;
			int ny = j;
			while (1) {
				nx += direct[idx][0];
				ny += direct[idx][1];

				if (nx < 1 || ny < 1 || nx > 19 || ny > 19) break;
				if (list[i][j] != list[nx][ny]) break;

				cnt++;
			}

			if (cnt == 5) {
				nx = i - direct[idx][0];
				ny = j - direct[idx][1];
				if (nx >= 1 && ny >= 1 && nx <= 19 && ny <= 19) {
					if (list[nx][ny] == list[i][j]) continue;
				}
				cout << list[i][j] << '\n' << i << ' ' << j << '\n';
				return true;
			}
		}
	}

	return false;
}

bool solve2() {
	int idx = 1;
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 15; j++) {
			if (!list[i][j]) continue;

			int cnt = 1;
			int nx = i;
			int ny = j;
			while (1) {
				nx += direct[idx][0];
				ny += direct[idx][1];

				if (nx < 1 || ny < 1 || nx > 19 || ny > 19) break;
				if (list[i][j] != list[nx][ny]) break;

				cnt++;
			}

			if (cnt == 5) {
				nx = i - direct[idx][0];
				ny = j - direct[idx][1];
				if (nx >= 1 && ny >= 1 && nx <= 19 && ny <= 19) {
					if (list[nx][ny] == list[i][j]) continue;
				}
				cout << list[i][j] << '\n' << i << ' ' << j << '\n';
				return true;
			}
		}
	}

	return false;
}

bool solve3() {
	int idx = 2;
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 15; j++) {
			if (!list[i][j]) continue;

			int cnt = 1;
			int nx = i;
			int ny = j;
			while (1) {
				nx += direct[idx][0];
				ny += direct[idx][1];

				if (nx < 1 || ny < 1 || nx > 19 || ny > 19) break;
				if (list[i][j] != list[nx][ny]) break;

				cnt++;
			}

			if (cnt == 5) {
				nx = i - direct[idx][0];
				ny = j - direct[idx][1];
				if (nx >= 1 && ny >= 1 && nx <= 19 && ny <= 19) {
					if (list[nx][ny] == list[i][j]) continue;
				}
				cout << list[i][j] << '\n' << i << ' ' << j << '\n';
				return true;
			}
		}
	}

	return false;
}

bool solve4() {
	int idx = 3;
	for (int i = 1; i <= 15; i++) {
		for (int j = 1; j <= 19; j++) {
			if (!list[i][j]) continue;

			int cnt = 1;
			int nx = i;
			int ny = j;
			while (1) {
				nx += direct[idx][0];
				ny += direct[idx][1];

				if (nx < 1 || ny < 1 || nx > 19 || ny > 19) break;
				if (list[i][j] != list[nx][ny]) break;

				cnt++;
			}

			if (cnt == 5) {
				nx = i - direct[idx][0];
				ny = j - direct[idx][1];
				if (nx >= 1 && ny >= 1 && nx <= 19 && ny <= 19) {
					if (list[nx][ny] == list[i][j]) continue;
				}
				cout << list[i][j] << '\n' << i << ' ' << j << '\n';
				return true;
			}
		}
	}

	return false;
}

void func() {
	if (!solve1()) {
		if (!solve2()) {
			if (!solve3()) {
				if (!solve4()) {
					cout << "0\n";
				}
			}
		}
	}
}

void input() {
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
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