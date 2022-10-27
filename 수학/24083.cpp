#include <iostream>
#define MOD 12
using namespace std;

int A, B;

void func() {
	int ans = (A + B) % MOD;
	if (!ans) ans = 12;

	cout << ans << '\n';
}

void input() {
	cin >> A >> B;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}