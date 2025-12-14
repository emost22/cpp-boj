#include <iostream>
using namespace std;

int L, R, A;

void func() {
	if (L > R) swap(L, R);

	int diff = R - L;
	if (diff < A) {
		cout << (R << 1) + ((A - diff) - ((A - diff) & 1)) << '\n';
	}
	else {
		cout << ((L + A) << 1) << '\n';
	}
}

void input() {
	cin >> L >> R >> A;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}