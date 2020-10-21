#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int sum, check;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> str;
	for (int i = 0; str[i]; i++) {
		sum += (str[i] - 48);
		if (str[i] == '0') check = 1;
	}
	if (check && sum % 3 == 0) {
		sort(str.begin(), str.end());
		for (int i = str.size() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << '\n';
	}
	else {
		cout << "-1\n";
	}

	return 0;
}