#include <iostream>
#define MOD 998244353
using namespace std;
typedef long long ll;

ll N;

ll** calMatrix(ll** x, ll** y) {
	ll** ret = new ll * [] { new ll[]{ 0,0,0 }, new ll[]{ 0,0,0 }, new ll[]{ 0,0,0 } };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

ll** power(ll** x, ll t) {
	ll** ret = new ll * [] { new ll[]{ 1,0,0 }, new ll[]{ 0,1,0 }, new ll[]{ 0,0,1 } };
	while (t) {
		if (t & 1) ret = calMatrix(ret, x);
		x = calMatrix(x, x);
		t >>= 1;
	}
	return ret;
}

void func() {
	ll** x = new ll * [] { new ll[]{ 0,1,0 }, new ll[]{ 0,0,1 }, new ll[]{ 1,1,0 } };
	ll** ret = power(x, N);
	cout << ret[2][1] << '\n';
}

void input() {
	cin >> N;
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