#include <iostream>
#include <string>
using namespace std;

string list[4] = { "`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;\'", "ZXCVBNM,./" };
string str;

void func() {
	int N = str.size();
	for (int i = 0; i < N; i++) {
		if (str[i] == ' ') {
			cout << ' ';
			continue;
		}

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < list[j].size(); k++) {
				if (str[i] == list[j][k]) {
					cout << list[j][k - 1];
				}
			}
		}
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (getline(cin, str)) {
		func();
	}

	return 0;
}