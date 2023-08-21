#include <iostream>
using namespace std;

int N;

void func() {
	cout << (N + 1) * N / 2 << ' ' << N * N << ' ' << (N + 1) * N << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}