#include <iostream>
#include <algorithm>
using namespace std;

int N, a, b, c;

void func() {
	if (N == 1) {
		cout << "0 0\n";
		return;
	}

	int ret = 0;
	if (a < c || b < c) ret = min(a, b) * (N - 1);
	else ret = min(a, b) + (N - 2) * c;
	
	cout << ret / 100 << ' ' << ret % 100 << '\n';
}

void input() {
	cin >> N >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}