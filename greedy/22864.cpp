#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, M;

void func() {
	int t = 24;
	int p = 0;
	int ret = 0;
	while (t--) {
		if (p + A <= M) {
			ret += B;
			p += A;
		}
		else {
			p = max(0, p - C);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> A >> B >> C >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}