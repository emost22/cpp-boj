#include <iostream>
#include <algorithm>
using namespace std;

int s, d, i, l, N;

void func() {
	cout << max(0, (N << 2) - s - d - i - l) << '\n';
}

void input() {
	cin >> s >> d >> i >> l >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}