#include <iostream>
using namespace std;

int alpha[26], MAX;
char st[5001];

void input() {
	while (cin >> st) {
		for (int i = 0; st[i]; i++) {
			alpha[st[i] - 'a']++;
			if (MAX < alpha[st[i] - 'a']) {
				MAX = alpha[st[i] - 'a'];
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (MAX == alpha[i]) {
			cout << (char)(i + 97);
		}
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}