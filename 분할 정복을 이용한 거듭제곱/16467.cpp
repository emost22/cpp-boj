#include <iostream>
#include <vector>
#define MOD 100000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vvl;

int K, N;

vvl calMatrix(vvl x, vvl y) {
	vvl ret(K + 1, vector<ll>(K + 1));
	for (int i = 0; i < K + 1; i++) {
		for (int j = 0; j < K + 1; j++) {
			for (int k = 0; k < K + 1; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

vvl powerMatrix(vvl x, int y) {
	vvl ret(K + 1, vector<ll>(K + 1));
	for (int i = 0; i < K + 1; i++) {
		ret[i][i] = 1;
	}

	while (y) {
		if (y & 1) ret = calMatrix(ret, x);
		x = calMatrix(x, x);
		y >>= 1;
	}
	return ret;
}

ll powerNum(ll x, int y) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return ret;
}

void func() {
	if (!K) {
		cout << powerNum(2LL, N) << '\n';
		return;
	}

	vvl v(K + 1, vector<ll>(K + 1));
	v[0][0] = v[0][K] = 1;
	for (int i = 1; i < K + 1; i++) {
		v[i][i - 1] = 1;
	}

	vvl ret = powerMatrix(v, N);
	cout << ret[0][0] << '\n';
}

void input() {
	cin >> K >> N;
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