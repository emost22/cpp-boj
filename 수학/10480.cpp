#include <iostream>
using namespace std;

int x;

void func() {
	if (x & 1) cout << x << " is odd\n";
	else cout << x << " is even\n";
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}