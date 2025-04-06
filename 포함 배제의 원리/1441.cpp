#include <iostream>
#define MAX 19
using namespace std;
typedef long long ll;

ll list[MAX];
ll L, R;
int N;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	return x * y / gcd(x, y);
}

void func() {
	ll ret = 0;
	for (int i = 1; i < (1 << N); i++) {
		int cnt = 0;
		ll tmp = 1;
		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			cnt++;
			tmp = lcm(tmp, list[j]);
			if (tmp > R) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		if (cnt & 1) ret += (R / tmp - (L - 1LL) / tmp);
		else  ret -= (R / tmp - (L - 1LL) / tmp);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
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