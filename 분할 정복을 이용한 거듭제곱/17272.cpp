#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > vvl;

ll N;
int M;

vvl calMatrix(vvl x, vvl y) {
	vvl ret(M, vector<ll>(M));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				ret[i][j] = (ret[i][j] + x[i][k] * y[k][j]) % MOD;
			}
		}
	}
	return ret;
}

vvl power(vvl x, ll y) {
	vvl ret(M, vector<ll>(M));
	for (int i = 0; i < M; i++) {
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
	vvl x(M, vector<ll>(M));
	x[0][0] = x[0][M - 1] = 1;
	for (int i = 1; i < M; i++) {
		x[i][i - 1] = 1;
	}

	vvl ret = power(x, N);
	cout << ret[0][0] << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}