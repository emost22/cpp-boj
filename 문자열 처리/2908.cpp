#include <iostream>
#include <string>
using namespace std;

string a, b;
bool win;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b;

	for (int i = 2; i >= 0; i--) {
		if (a[i] > b[i]) {
			win = true;
			break;
		}
		else if (a[i] < b[i]) {
			win = false;
			break;
		}
	}

	if (win) {
		cout << a[2] << a[1] << a[0] << '\n';
	}
	else {
		cout << b[2] << b[1] << b[0] << '\n';
	}

	return 0;
}