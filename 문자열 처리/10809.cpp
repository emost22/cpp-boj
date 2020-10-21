#include <iostream>
#include <memory.h>
using namespace std;

char str[100];
int num[26];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(num, -1, sizeof(num));
	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (num[str[i] - 97] != -1) continue;

		num[str[i] - 97] = i;
	}

	for (int i = 0; i < 26; i++) {
		cout << num[i] << ' ';
	}
	cout << '\n';

	return 0;
}