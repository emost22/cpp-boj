#include <iostream>
#include <algorithm>
using namespace std;

int A, B, K, X;

void func() {
	if (K + X < A || K - X > B) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	cout << min(B, K + X) - max(A, K - X) + 1 << '\n';
}

void input() {
	cin >> A >> B >> K >> X;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}