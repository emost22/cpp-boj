#include <iostream>
using namespace std;

int r, e, c;

void func() {
	if (r < e - c) {
		cout << "advertise\n";
	}
	else if (r > e - c) {
		cout << "do not advertise\n";
	}
	else {
		cout << "does not matter\n";
	}
}

void input() {
	cin >> r >> e >> c;
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