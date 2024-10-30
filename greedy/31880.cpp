#include <iostream>
using namespace std;
typedef long long ll;

int N, M;

void func() {
	ll ret = 0;
	
	ll x;
	while (N--) {
		cin >> x;
		ret += x;
	}

	while (M--) {
		cin >> x;
		if (!x) continue;
		ret *= x;
	}
	
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}