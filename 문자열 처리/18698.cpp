#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int len = str.size();
	int ans = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'D') break;

		ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}