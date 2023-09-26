#include <iostream>
#define MOD 14579
using namespace std;

int l, r;

void func() {
	int ret = 0;
	for (int i = 1; i <= l; i++) {
		ret = (ret + i) % MOD;
	}
	int sum = ret;
	for (int i = l + 1; i <= r; i++) {
		sum = (sum + i) % MOD;
		ret = (ret * sum) % MOD;
	}

	cout << ret << '\n';
}

void input() {
	cin >> l >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}