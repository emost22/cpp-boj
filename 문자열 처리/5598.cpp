#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] > 67) str[i] -= 3;
		else str[i] += 23;

		cout << str[i];
	}
	cout << '\n';

	return 0;
}