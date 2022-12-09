#include <iostream>
using namespace std;
typedef long long ll;

ll k, w, m;

void func() {
	if (k >= w) cout << "0\n";
	else cout << (w - k) / m + ((w - k) % m != 0) << '\n';
}

void input() {
	cin >> k >> w >> m;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}