#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long ll;

ll N;

ll** calMatrix(ll** x, ll** y) {
	ll** ret = new ll * [] { new ll[]{ 0,0 }, new ll[]{ 0,0 } };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

ll power(ll t) {
	ll** x = new ll * [] { new ll[]{ 1,1 }, new ll[]{ 1,0 } };
	ll** ret = new ll * [] { new ll[]{ 1,0 }, new ll[]{ 0,1 } };
	while (t) {
		if (t & 1) ret = calMatrix(ret, x);
		x = calMatrix(x, x);
		t >>= 1;
	}
	return ret[0][0];
}

void func() {
	cout << power(N - 1LL) << '\n';
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