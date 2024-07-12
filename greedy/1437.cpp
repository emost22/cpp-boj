#include <iostream>
#define MOD 10007
using namespace std;

int N;

void func() {
	int ret = 1;
	while (N >= 5) {
		N -= 3;
		ret = (ret * 3) % MOD;
	}
	cout << (ret * N) % MOD << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}