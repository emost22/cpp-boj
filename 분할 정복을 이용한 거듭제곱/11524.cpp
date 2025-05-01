#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long ll;

ll N;
int t;

ll** calMatrix(ll** x, ll** y) {
	ll** ret = new ll * [2]{ new ll[2]{0,0}, new ll[2]{0,0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

ll power(ll** x, ll y) {
	ll** ret = new ll * [2]{ new ll[2]{1,0}, new ll[2]{0,1} };
	while (y) {
		if (y & 1) ret = calMatrix(ret, x);
		x = calMatrix(x, x);
		y >>= 1;
	}
	return ret[0][1];
}

void func() {
	ll** x = new ll * [2]{ new ll[2]{1,1}, new ll[2]{1,0} };
	cout << t << ' ' << power(x, N) << '\n';
}

void input() {
	cin >> t >> N;
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