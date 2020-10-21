#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char str[1000];
string solve[1000];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int e;

	cin >> str;
	for (int i = 0; str[i]; i++) {
		solve[i] = str + i;
		if (str[i + 1] == NULL) e = i + 1;
	}
	sort(solve, solve + e);
	for (int i = 0; solve[i] != ""; i++) {
		cout << solve[i] << '\n';
	}

	return 0;
}