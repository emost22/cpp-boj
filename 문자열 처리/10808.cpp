#include <iostream>
#include <string>
using namespace std;

string str;
int num[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;

	for (int i = 0; str[i]; i++) {
		num[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << num[i] << ' ';
	}
	cout << '\n';

	return 0;
}