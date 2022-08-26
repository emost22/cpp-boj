#include <iostream>
#include <algorithm>
using namespace std;

int D, P, Q;

void func() {
	if (!(D % P) || !(D % Q)) {
		cout << D << '\n';
		return;
	}
	if (P < Q) swap(P, Q);

	int N = D / P + 1;
	int ans = N * P;
	for (int i = N - 1; i >= 0; i--) {
		int x = (D - P * i) / Q;
		int mod = (D - P * i) % Q;
		
		if (!mod) {
			cout << D << '\n';
			return;
		}

		int ret = P * i + (x + 1) * Q;
		if (ans == ret) {
			cout << ans << '\n';
			return;
		}
		
		ans = min(ans, ret);
	}

	cout << ans << '\n';
}

void input() {
	cin >> D >> P >> Q;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}