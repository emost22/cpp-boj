#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;

void func() {
	int mn = N - M * K;
	int mx = mn + M - 1;
	cout << max(0, mn) << ' ' << max(0, mx) << '\n';
}

void input() {
	cin >> N >> M >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}