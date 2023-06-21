#include <iostream>
#define MOD 45678
using namespace std;

int N;

void func() {
	int ret = 1;
	int add = 4;
	for (int i = 0; i < N; i++) {
		ret = (ret + add) % MOD;
		add = (add + 3) % MOD;
	}

	cout << ret << '\n';
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