#include <iostream>
#include <vector>
#define MOD 100
using namespace std;
typedef vector<vector<int> > vvii;

vvii v;
int x, y, a0, a1, N;

vvii fibo(vvii a, vvii b) {
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
	if (n == 1) return v;

	if (n % 2) {
		vvii pre = solve(n - 1);
		return fibo(pre, v);
	}
	else {
		vvii pre = solve(n / 2);
		return fibo(pre, pre);
	}
}

void func() {
	if (!N) {
		cout << a0 << '\n';
		return;
	}
	if (N == 1) {
		cout << a1 << '\n';
		return;
	}

	vvii ret = solve(N - 1);
	int ans = (ret[0][0] * a1 + ret[0][1] * a0) % MOD;
	
	cout << ans << '\n';
}

void input() {
	cin >> x >> y >> a0 >> a1 >> N;
	v.push_back({ x, y });
	v.push_back({ 1, 0 });
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout.width(2); cout.fill('0');

	input();
	func();

	return 0;
}