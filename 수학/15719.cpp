#include <iostream>
using namespace std;
typedef long long ll;

void input() {
	ll N;
	cin >> N;

	ll ret = N * (N - 1LL) >> 1;
	ll x;
	while (N--) {
		cin >> x;
		ret -= x;
	}

	cout << -ret << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}