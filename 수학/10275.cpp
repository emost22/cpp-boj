#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;
int n;

void func() {
	ll x = (1LL << n);

	int ret = 0;
	while (x && a && b) {
		x >>= 1;
		bool flag = false;
		if (a >= x) {
			a -= x;
			flag = true;
		}

		if (b >= x) {
			b -= x;
			flag = true;
		}

		ret += flag;
	}

	cout << ret << '\n';
}

void input() {
	cin >> n >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}