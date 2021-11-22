#include <iostream>
using namespace std;

int N;

void func() {
	int ans = 0;
	while (N) {
		if (N & 1) ans++;
		N >>= 1;
	}

	cout << ans << '\n';
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