#include <iostream>
#define MAX 7
using namespace std;

int cnt[2][MAX];
int price[2][MAX];
int a, b;

void init() {
	int c = 1;
	for (int i = 1; i <= 6; i++) {
		cnt[0][i] = c++;
	}
	
	c = 1;
	for (int i = 1; i <= 5; i++) {
		cnt[1][i] = c;
		c <<= 1;
	}

	price[0][1] = 5000000;
	price[0][2] = 3000000;
	price[0][3] = 2000000;
	price[0][4] = 500000;
	price[0][5] = 300000;
	price[0][6] = 100000;
	price[1][1] = 5120000;
	price[1][2] = 2560000;
	price[1][3] = 1280000;
	price[1][4] = 640000;
	price[1][5] = 320000;
}

void func() {
	int ret = 0;
	for (int i = 1; a > 0 && i <= 6; i++) {
		if (a <= cnt[0][i]) {
			ret += price[0][i];
			break;
		}

		a -= cnt[0][i];
	}

	for (int i = 1; b > 0 && i <= 5; i++) {
		if (b <= cnt[1][i]) {
			ret += price[1][i];
			break;
		}

		b -= cnt[1][i];
	}

	cout << ret << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}