#include <iostream>
using namespace std;

int N;
char c;

void func(int tc) {
	if (tc > 1) cout << '\n';

	int x = c - 'A';
	for (int i = 1; i <= N; i++, x = (x + 1) % 26) {
		for (int j = 1; j <= i; j++) {
			cout << (char)(x + 'A');
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> c;
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