#include <iostream>
using namespace std;

char str[15];
int cnt;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] < 'S') {
			cnt += (str[i] - 65) / 3 + 3;
		}
		else {
			if (str[i] == 'S') cnt += 8;
			else if (str[i] > 'V') cnt += 10;
			else cnt += 9;
		}
	}

	cout << cnt << '\n';

	return 0;
}