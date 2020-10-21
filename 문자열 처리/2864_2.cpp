#include <iostream>
#include <string>
using namespace std;

string a, b;
int mina, maxa, minb, maxb;

int main() {
	cin >> a >> b;
	for (int i = 0; a[i]; i++) {
		if (a[i] == '6') a[i] = '5';
	}
	mina = stoi(a);

	for (int i = 0; a[i]; i++) {
		if (a[i] == '5') a[i] = '6';
	}
	maxa = stoi(a);

	for (int i = 0; b[i]; i++) {
		if (b[i] == '6') b[i] = '5';
	}
	minb = stoi(b);

	for (int i = 0; b[i]; i++) {
		if (b[i] == '5') b[i] = '6';
	}
	maxb = stoi(b);

	cout << mina + minb << ' ' << maxa + maxb << '\n';

	return 0;
}