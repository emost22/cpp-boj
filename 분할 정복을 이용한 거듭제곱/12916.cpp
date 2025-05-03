#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vvl;

vvl v;
int N, K;

vvl calMatrix(vvl x, vvl y) {
	vvl ret(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

vvl power(vvl x, int y) {
	vvl ret(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		ret[i][i] = 1;
	}

	while (y) {
		if (y & 1) ret = calMatrix(ret, x);
		x = calMatrix(x, x);
		y >>= 1;
	}
	return ret;
}

void func() {
	vvl x = power(v, K);

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret = (ret + x[i][j]) % MOD;
		}
	}
	cout << ret << '\n';
}

void input() {
	ll x;
	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}