#include <iostream>
using namespace std;
typedef long long ll;

ll N;
int K, Q, cnt;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	ll x, y;
	cin >> N >> K >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;

		if (K == 1) {
			cout << abs(x - y) << '\n';
			continue;
		}

		while (1) {
			if (x == y) break;

			if (x < y) {
				y = (y + K - 2) / K;
			}
			else x = (x + K - 2) / K;
			cnt++;
		}
		cout << cnt << '\n';
		cnt = 0;
	}

	return 0;
}