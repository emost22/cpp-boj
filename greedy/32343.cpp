#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a, b;

void func() {
	int ret = (1 << N) - 1;
	int sub = abs(N - a - b);
	int bit = 1;
	while (sub--) {
		ret ^= bit;
		bit <<= 1;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}