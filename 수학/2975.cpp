#include <iostream>
using namespace std;

char ch;
int x, y;

void func() {
	if (ch == 'W') {
		if (x - y < -200) cout << "Not allowed\n";
		else cout << x - y << '\n';
	}
	else {
		cout << x + y << '\n';
	}
}

void input() {
	cin >> x >> ch >> y;
	if (!x && !y && ch == 'W') exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}