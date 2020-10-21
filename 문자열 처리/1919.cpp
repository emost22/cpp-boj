#include <iostream>
using namespace std;

char st[2][1001];
int alpha[26];
int sum, ans;

void func() {
	for (int i = 0; st[0][i]; i++) {
		alpha[st[0][i] - 'a']++;
		sum++;
	}

	for (int i = 0; st[1][i]; i++) {
		sum++;
		if (!alpha[st[1][i] - 'a']) continue;
		else {
			alpha[st[1][i] - 'a']--;
			ans += 2;
		}
	}

	cout << sum - ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> st[0] >> st[1];
	func();

	return 0;
}