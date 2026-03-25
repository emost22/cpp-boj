#include <iostream>
using namespace std;

int N, T;

void func() {
	N <<= 1;
	int x = (N << 1) - 2;
	int t = T % x;
	if (!t) t = x;

	if (t > N) cout << N - (t - N) << '\n';
	else cout << N - (N - t) << '\n';
}

void input() {
	cin >> N >> T;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}