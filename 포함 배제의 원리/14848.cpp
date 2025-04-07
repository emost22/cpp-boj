#include <iostream>
#define MAX 15
using namespace std;
typedef long long ll;

ll list[MAX];
ll N;
int K;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}

void func() {
	ll ret = 0;
	for (int i = 1; i < (1 << K); i++) {
		int cnt = 0;
		ll tmp = 1LL;
		bool flag = false;
		for (int j = 0; j < K; j++) {
			if (!(i & (1 << j))) continue;
			cnt++;
			tmp = lcm(tmp, list[j]);
			if (tmp > N) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		if (cnt & 1) ret += (N / tmp);
		else ret -= (N / tmp);
	}
	cout << N - ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}