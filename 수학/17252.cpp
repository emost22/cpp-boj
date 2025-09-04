#include <iostream>
#define MAX 19
using namespace std;

int x;

void func() {
	if (!x) {
		cout << "NO\n";
		return;
	}

	int m = 1;
	for (int i = 0; i < MAX; i++) {
		m *= 3;
	}

	for (int i = m; i > 0; i /= 3) {
		if (x < i) continue;
		x -= i;
	}

	if (!x) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}