#include <iostream>
#include <string>
using namespace std;

string str;
int alphabet[26];
int odd, even, idx;
char oddch, ans[25];

void func() {
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] && alphabet[i] % 2) {
			odd++;
			oddch = i + 'A';
			for (int j = 0; j < alphabet[i] / 2; j++) {
				ans[idx++] = i + 'A';
			}
		}
		else if (alphabet[i] && !(alphabet[i] % 2)) {
			even++;
			for (int j = 0; j < alphabet[i] / 2; j++) {
				ans[idx++] = i + 'A';
			}
		}
	}

	if (str.size() % 2 && odd != 1) {
		cout << "I\'m Sorry Hansoo" << '\n';
		return;
	}
	if (!(str.size() % 2) && odd) {
		cout << "I\'m Sorry Hansoo" << '\n';
		return;
	}

	for (int i = 0; i < idx; i++) {
		cout << ans[i];
	}
	if (odd) cout << oddch;
	for (int i = idx - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << '\n';
}

void input() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		alphabet[str[i] - 'A']++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}