#include <iostream>
#include <string>
using namespace std;

string str[5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (i < str[j].length()) cout << str[j][i];
		}
	}
	cout << '\n';

	return 0;
}