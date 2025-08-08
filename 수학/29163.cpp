#include <iostream>
using namespace std;

int N;

void func() {
	int odd = 0;
	int even = 0;
	int x;
	while (N--) {
		cin >> x;
		if (x & 1) odd++;
		else even++;
	}

	if (even > odd) cout << "Happy\n";
	else cout << "Sad\n";
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}