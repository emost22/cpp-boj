#include <iostream>
using namespace std;

int N, K;

void func() {
	if (N < K * (K + 1) / 2) {
		cout << "-1\n";
		return;
	}
	N -= (K * (K + 1) / 2);

	if (N % K) cout << K << '\n';
	else cout << K - 1 << '\n';
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}