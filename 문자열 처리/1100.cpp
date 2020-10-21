#include <iostream>
using namespace std;

char str[8];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int cnt = 0;

	for (int T = 0; T < 8; T++) {
		cin >> str;
		if (T % 2 == 0) {
			for (int i = 0; i < 8; i++) {
				if (str[i] == 'F' && i % 2 == 0) {
					cnt++;
				}
			}
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (str[i] == 'F' && i % 2 == 1) {
					cnt++;
				}
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}