#include <iostream>
using namespace std;
typedef long long ll;

ll N, M, T, S;

void func() {
	ll zs = (N - 1) >> 3;
	ll zret = zs * S + N;

	ll ds = (M - 1) >> 3;
	ll dret = ds * S + M + (T << 1) * ds + T;

	if (zret > dret) {
		cout << "Dok\n" << dret << '\n';
	}
	else {
		cout << "Zip\n" << zret << '\n';
	}
}

void input() {
	cin >> N >> M >> T >> S;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}