#include <iostream>
using namespace std;

char str[1000000], x;
int num[26], max_value, cnt;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] < 97) {
			str[i] -= 65;
		}
		else {
			str[i] -= 97;
		}

		num[str[i]]++;
		max_value = Max(max_value, num[str[i]]);
	}
	for (int i = 0; i < 26; i++) {
		if (max_value == num[i]) {
			cnt++;
			x = i + 65;
		}
	}

	if (cnt == 1) cout << x << '\n';
	else cout << "?\n";

	return 0;
}