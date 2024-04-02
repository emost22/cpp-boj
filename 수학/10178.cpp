#include <iostream>
using namespace std;

int c, v;

void func() {
	cout << "You get " << c / v << " piece(s) and your dad gets " << c % v << " piece(s).\n";
}

void input() {
	cin >> c >> v;
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