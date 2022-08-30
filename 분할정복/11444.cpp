#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vvll;

vvll v = { {1,1},{1,0} };
ll N;

vvll mulMatrix(vvll a, vvll b) {
	vvll ret = { {0,0},{0,0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	return ret;
}

vvll fibo(ll n) {
	if (n == 1) return v;

	if (n % 2) {
		vvll pre = fibo(n - 1LL);
		return mulMatrix(pre, v);
	}
	else {
		vvll pre = fibo(n / 2LL);
		return mulMatrix(pre, pre);
	}
}

void func() {
	vvll ans = fibo(N);
	cout << ans[0][1] << '\n';
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