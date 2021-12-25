#include <iostream>
using namespace std;
typedef long long ll;

ll x, y;
int N;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		cout << x * y / gcd(x, y) << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}