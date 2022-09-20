#include <iostream>
using namespace std;

int a, b, c, d;

void func() {

	if (a + d < b + c) {
		cout << "Esteghlal\n";
	}
	else if (a + d > b + c) {
		cout << "Persepolis\n";
	}
	else {
		if (b > d) {
			cout << "Esteghlal\n";
		}
		else if (b < d) {
			cout << "Persepolis\n";
		}
		else {
			cout << "Penalty\n";
		}
	}
}

void input() {
	cin >> a >> b >> c >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}