#include <iostream>
#define LOG 31
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll ret = 0;
	for (int i = 1; i < LOG; i++) {
		if ((1 << i) > N) break;
		ret += ((ll)(1LL << i) * (ll)((N / (1LL << i) + 1LL) >> 1));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	N <<= 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}