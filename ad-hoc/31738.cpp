#include <iostream>
using namespace std;
typedef long long ll;

ll N, M;

void func() {
	if (N >= M) {
		cout << "0\n";
		return;
	}

	ll ret = 1;
	for (ll i = 2; i <= N; i++) {
		ret = (ret * i) % M;
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