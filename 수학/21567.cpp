#include <iostream>
using namespace std;
typedef long long ll;

ll a, b, c;

void func() {
	ll x = a * b * c;
	int cnt[10] = { 0, };
	while (x) {
		cnt[x % 10]++;
		x /= 10;
	}

	for (auto c : cnt) {
		cout << c << '\n';
	}
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}