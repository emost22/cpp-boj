#include <iostream>
#include <string>
using namespace std;

string list[4][5];
int bit[10];

void removeBit(int idx, int x) {
	bit[idx] &= ~(1 << x);
}

void init() {
	bit[0] = (1 << 16) - 1;
	bit[1] = (1 << 16) - 1;
	bit[2] = (1 << 16) - 1;
	bit[3] = (1 << 16) - 1;
	bit[4] = (1 << 16) - 1;
	bit[5] = (1 << 16) - 1;
	bit[6] = (1 << 16) - 1;
	bit[7] = (1 << 16) - 1;
	bit[8] = (1 << 16) - 1;
	bit[9] = (1 << 16) - 1;

	removeBit(0, 4);
	removeBit(0, 7);
	removeBit(0, 10);

	removeBit(1, 0);
	removeBit(1, 1);
	removeBit(1, 3);
	removeBit(1, 4);
	removeBit(1, 6);
	removeBit(1, 7);
	removeBit(1, 9);
	removeBit(1, 10);
	removeBit(1, 12);
	removeBit(1, 13);

	removeBit(2, 3);
	removeBit(2, 4);
	removeBit(2, 10);
	removeBit(2, 11);

	removeBit(3, 3);
	removeBit(3, 4);
	removeBit(3, 9);
	removeBit(3, 10);

	removeBit(4, 1);
	removeBit(4, 4);
	removeBit(4, 9);
	removeBit(4, 10);
	removeBit(4, 12);
	removeBit(4, 13);

	removeBit(5, 4);
	removeBit(5, 5);
	removeBit(5, 9);
	removeBit(5, 10);

	removeBit(6, 4);
	removeBit(6, 5);
	removeBit(6, 10);

	removeBit(7, 3);
	removeBit(7, 4);
	removeBit(7, 6);
	removeBit(7, 7);
	removeBit(7, 9);
	removeBit(7, 10);
	removeBit(7, 12);
	removeBit(7, 13);

	removeBit(8, 4);
	removeBit(8, 10);

	removeBit(9, 4);
	removeBit(9, 9);
	removeBit(9, 10);
}

void func() {
	string ans;
	for (int k = 0; k < 4; k++) {
		int cnt = 0;
		int x = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 3; j++) {
				if (list[k][i][j] == '#') {
					x |= (1 << cnt);
				}
				cnt++;
			}
		}

		for (int i = 0; i < 10; i++) {
			if ((x & bit[i]) == x) {
				ans += i + '0';
				break;
			}
		}

		if (k == 1) ans += ':';
	}

	cout << ans << '\n';
}

void input() {
	char ch;
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 4; k++) {
			cin >> list[k][i];
		}
	}
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}