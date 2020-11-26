#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll N, P, Q;
map<ll, ll> m;

ll func(ll n, ll p, ll q) {
	if (m.find(n) != m.end()) {
		return m.find(n)->second;
	}

	ll A = func(n / p, p, q) + func(n / q, p, q);
	m.insert({ n, A });
	return A;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P >> Q;
	m.insert({ 0,1 });
	cout << func(N, P, Q) << '\n';

	return 0;
}