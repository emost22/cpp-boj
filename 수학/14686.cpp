#include <iostream>
#define MAX 100001
using namespace std;

int list[2][MAX];
int N;

void func() {
	int ret = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < N; i++) {
		x += list[0][i];
		y += list[1][i];
		if (x == y) ret = i + 1;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < 2; i++) {
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