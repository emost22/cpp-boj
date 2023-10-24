#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll ret = 0;
	for (ll i = 1; i < N; i++) {
		ret += ((N + 1) * i);
	}

	cout << ret << '\n';
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