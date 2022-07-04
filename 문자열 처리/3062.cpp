#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

void func() {
	int ans = stoi(str);
	reverse(str.begin(), str.end());
	str = to_string(ans + stoi(str));

	int l = 0;
	int r = str.size() - 1;
	while (l <= r) {
		if (str[l] != str[r]) {
			cout << "NO\n";
			return;
		}
		l++;
		r--;
	}

	cout << "YES\n";
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