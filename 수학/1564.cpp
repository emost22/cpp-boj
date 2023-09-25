#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll ret = 1LL;
	ll mod = 1e12;
	for (ll i = 1LL; i <= N; i++) {
		ret *= i;
		while (!(ret % 10LL)) {
			ret /= 10LL;
		}
		ret %= mod;
	}

	string str = to_string(ret % 100000);
	while (str.size() < 5) {
		str = "0" + str;
	}
	
	cout << str << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}