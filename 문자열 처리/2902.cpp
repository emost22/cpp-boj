#include <iostream>
using namespace std;

char str[100];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (65 <= str[i] && str[i] <= 90) {
			cout << str[i];
		}
	}
	cout << '\n';

	return 0;
}