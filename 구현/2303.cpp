#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX][5];
int N;

int getBigNumber(int idx) {
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				ret = max(ret, (list[idx][i] + list[idx][j] + list[idx][k]) % 10);
			}
		}
	}
	return ret;
}

void func() {
	int ret = 0;
	int bn = -1;
	for (int i = N - 1; i >= 0; i--) {
		if (bn == 9) break;

		int number = getBigNumber(i);
		if (bn >= number) continue;

		bn = number;
		ret = i + 1;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i][0] >> list[i][1] >> list[i][2] >> list[i][3] >> list[i][4];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}