#include <iostream>
#include <string>
using namespace std;

string x, y;

void func() {
	int xLen = x.size();
	int yLen = y.size();

	if (xLen != yLen) {
		cout << "ERROR\n";
		return;
	}

	for (int i = 0; i < xLen; i++) {
		if (x[i] != y[i]) {
			cout << "ERROR\n";
			return;
		}
	}

	cout << "OK\n";
}

void input() {
	cin >> x >> y;
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