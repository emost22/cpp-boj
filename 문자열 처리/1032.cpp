#include <iostream>
#include <memory.h>
using namespace std;

char str1[50], str2[50];
bool num[50];
int N;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> str1;

	memset(num, true, sizeof(num));
	while (N-- - 1) {
		cin >> str2;
		for (int i = 0; str1[i]; i++) {
			if (num[i]) {
				if (str1[i] != str2[i]) {
					num[i] = false;
				}
			}
		}
	}

	for (int i = 0; str1[i]; i++) {
		if (num[i]) cout << str1[i];
		else cout << '?';
	}
	cout << '\n';

	return 0;
}