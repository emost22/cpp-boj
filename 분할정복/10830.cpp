#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 5
#define MOD 1000
using namespace std;
typedef long long ll;
typedef vector<vector<int> > vvii;

vvii v;
ll M;
int N;

vvii mulMatrix(vvii m1, vvii m2) {
	vvii ret = vector<vector<int> >(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] = (ret[i][j] + m1[i][k] * m2[k][j]) % MOD;
			}
		}
	}

	return ret;
}

vvii solve(ll m) {
	if (m == 1) return v;

	if (m % 2) {
		vvii pre = solve(m - 1LL);
		return mulMatrix(pre, v);
	}
	else {
		vvii pre = solve(m / 2LL);
		return mulMatrix(pre, pre);
	}
}

void func() {
	vvii ans = solve(M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	v.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
			v[i][j] %= MOD;
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