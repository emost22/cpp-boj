#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long ll;

unordered_set<ll> s;
ll k;

void func() {
	for (ll x = k; ; x += k) {
		if (s.find(x) != s.end()) continue;
		cout << x << '\n';
		return;
	}
}

void input() {
	int N;
	ll x;
	cin >> N >> k;
	while (N--) {
		cin >> x;
		s.insert(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}