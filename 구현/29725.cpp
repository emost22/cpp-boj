#include <iostream>
#define MAX 8
using namespace std;

char list[MAX + 1][MAX + 1];

int getScore(char x) {
	if (x == 'K' || x == 'k') return 0;
	if (x == 'P') return 1;
	if (x == 'p') return -1;
	if (x == 'N' || x == 'B') return 3;
	if (x == 'n' || x == 'b') return -3;
	if (x == 'R') return 5;
	if (x == 'r') return -5;
	if (x == 'Q') return 9;
	if (x == 'q') return -9;
	return 0;
}

void func() {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			ret += getScore(list[i][j]);
		}
	}
	cout << ret << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
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