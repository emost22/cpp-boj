#include <iostream>
#include <algorithm>
#define MAX 300000
#define MOD 1000000007
using namespace std;
typedef long long ll;

int list[MAX];
int N;

ll power(ll x, int y) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ret;
}

void func() {
	sort(list, list + N);

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret = (ret + list[i] * (power(2, i) - power(2, N - i - 1) + MOD)) % MOD;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}