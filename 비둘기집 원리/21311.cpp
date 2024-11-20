#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
int pos[26], cnt[26];
int len;

void func() {
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < len; i++) {
		if (pos[str[i] - 'a'] == -1) {
			pos[str[i] - 'a'] = i;
			cnt[str[i] - 'a']++;
			continue;
		}

		if ((i - pos[str[i] - 'a'] + 1) & 1) {
			cout << "NO\n";
			return;
		}
		pos[str[i] - 'a'] = i;
		cnt[str[i] - 'a']++;
		if (cnt[str[i] - 'a'] > 2) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}