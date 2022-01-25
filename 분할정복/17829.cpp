#include <iostream>
#include <algorithm>
#define MAX 1024
using namespace std;

int list[MAX][MAX];
int N;

int solve(int sx, int sy, int lsize) {
	if (lsize == 2) {
		int a = -1;
		int b = -1;
		for (int i = sx; i < sx + lsize; i++) {
			for (int j = sy; j < sy + lsize; j++) {
				if (a == -1) {
					a = list[i][j];
				}
				else {
					if (a < list[i][j]) {
						b = a;
						a = list[i][j];
					}
					else {
						if (b == -1) {
							b = list[i][j];
						}
						else {
							b = max(b, list[i][j]);
						}
					}
				}
			}
		}

		return b;
	}

	int ret[4];
	ret[0] = solve(sx, sy, lsize / 2);
	ret[1] = solve(sx, sy + lsize / 2, lsize / 2);
	ret[2] = solve(sx + lsize / 2, sy, lsize / 2);
	ret[3] = solve(sx + lsize / 2, sy + lsize / 2, lsize / 2);
	sort(ret, ret + 4);

	return ret[2];
}

void func() {
	cout << solve(0, 0, N) << '\n';
}

void input() {
	cin >> N;
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