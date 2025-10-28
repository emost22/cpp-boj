#include <iostream>
using namespace std;

int N;

bool isOnLine(int x, int y) {
	return !x || !y || x == N - 1 || y == N - 1;
}

void func(int tc) {
	if (tc > 1) cout << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isOnLine(i, j)) cout << '#';
			else cout << 'J';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}