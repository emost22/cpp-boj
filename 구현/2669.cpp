#include <iostream>
#define MAX 101
using namespace std;

int list[MAX][MAX];

void func() {
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			ret += list[i][j];
		}
	}

	cout << ret << '\n';
}

void input() {
	int sx, sy, ex, ey;
	for (int t = 0; t < 4; t++) {
		cin >> sx >> sy >> ex >> ey;

		for (int i = sx; i < ex; i++) {
			for (int j = sy; j < ey; j++) {
				list[i][j] = 1;
			}
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