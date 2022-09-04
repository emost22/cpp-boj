#include <iostream>
#include <vector>
#define MOD 10000
using namespace std;
typedef vector<vector<int> > vvii;

vvii v = { {1,1},{1,0} };
int N;

vvii mulMatrix(vvii a, vvii b) {
	vvii ret = { {0,0},{0,0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}

	return ret;
}

vvii solve(int n) {
	if (n == 0) return { {0,0},{0,0} };
	if (n == 1) return v;

	if (n % 2) {
		vvii pre = solve(n - 1);
		return mulMatrix(pre, v);
	}
	else {
		vvii pre = solve(n / 2);
		return mulMatrix(pre, pre);
	}
}

void func() {
	cout << solve(N)[0][1] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (N == -1) return 0;
		func();
	}
}