#include <iostream>
#include <vector>
#define MAX 8
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vvl;

vvl v;
int D;

void init() {
	v.resize(MAX, vector<ll>(MAX));
	v[0][1] = v[1][0] = 1;
	v[0][2] = v[2][0] = 1;

	v[1][2] = v[2][1] = 1;
	v[1][3] = v[3][1] = 1;

	v[2][3] = v[3][2] = 1;
	v[2][6] = v[6][2] = 1;

	v[3][4] = v[4][3] = 1;
	v[3][6] = v[6][3] = 1;

	v[4][5] = v[5][4] = 1;
	v[4][6] = v[6][4] = 1;

	v[5][7] = v[7][5] = 1;

	v[6][7] = v[7][6] = 1;
}

vvl calMatrix(vvl x, vvl y) {
	vvl ret(MAX, vector<ll>(MAX));
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

vvl power(vvl x, int y) {
	vvl ret(MAX, vector<ll>(MAX));
	for (int i = 0; i < MAX; i++) {
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
	init();

	vvl x = power(v, D);
	cout << x[0][0] << '\n';
}

void input() {
	cin >> D;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}