#include <iostream>
using namespace std;

int aa, ah, ba, bh;

void func() {
	while (ah > 0 && bh > 0) {
		ah -= ba;
		bh -= aa;
	}

	if (ah <= 0 && bh <= 0) cout << "DRAW\n";
	else if (ah <= 0) cout << "PLAYER B\n";
	else cout << "PLAYER A\n";
}

void input() {
	cin >> aa >> ah >> ba >> bh;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}