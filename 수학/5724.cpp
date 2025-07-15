#include <iostream>
using namespace std;

int N;

void func() {
	cout << N * (N + 1) * ((N << 1) + 1) / 6 << '\n';
}

void input() {
	cin >> N;
	if (!N) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}