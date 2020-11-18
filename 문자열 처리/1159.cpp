#include <iostream>
#include <string>
using namespace std;

int alphabet[26];

void func() {
	bool chk = false;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= 5) {
			chk = true;
			cout << (char)(i + 'a');
		}
	}
	if (!chk) cout << "PREDAJA";
	cout << '\n';
}

void input() {
	int N;
	string str;
	cin >> N;
	while (N--) {
		cin >> str;

		alphabet[str[0] - 'a']++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}