#include <iostream>
using namespace std;
typedef long long ll;

ll N, P;

void func() {
	ll ret = 1LL;
	for (ll i = 2LL; i <= N; i++) {
		ret = (ret * i) % P;
	}
	
	cout << ret << '\n';
}

void input() {
	cin >> N >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}