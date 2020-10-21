#include <iostream>
using namespace std;

int coin[10];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K, cindex = 0, ans = 0;
	cin >> N >> K;
	for (int i = N - 1; i >= 0; i--) {
		cin >> coin[i];
	}

	while (K) {
		if (coin[cindex] > K) cindex++;
		else {
			ans += K / coin[cindex];
			K %= coin[cindex];
			cindex++;
		}
	}

	cout << ans << '\n';

	return 0;
}