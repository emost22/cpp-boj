#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;

ll list[MAX];
int N;
ll M;

ll power(ll x, ll y) {
	ll ret = 1LL;
	while (y) {
		if (y & 1) ret = (ret * x) % M;
		x = (x * x) % M;
		y >>= 1;
	}
	return ret;
}

void func() {
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret = (ret + power(list[i], (ll)i + 2LL)) % M;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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