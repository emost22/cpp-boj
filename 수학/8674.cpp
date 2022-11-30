#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll x, y;

void func() {
	if (!(x % 2) || !(y % 2)) cout << "0\n";
	else cout << min(x, y) << '\n';
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}