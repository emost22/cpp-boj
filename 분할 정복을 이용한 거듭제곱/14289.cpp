#include <iostream>
#include <vector>
#define MAX 50
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vvl;

vvl v;
int N, M, D;

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
	vvl x = power(v, D);
	cout << x[0][0] << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	v.resize(N, vector<ll>(N));
	while (M--) {
		cin >> x >> y;
		v[x - 1][y - 1] = v[y - 1][x - 1] = 1;
	}

	cin >> D;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}