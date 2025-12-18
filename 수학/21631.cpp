#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;

void func() {
	if (b <= a) cout << b << '\n';
	else cout << a + 1 << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}