#include <iostream>
#include <string>
using namespace std;

string str;
int N, ans;

int isPalindrome(int l, int r) {
	ans++;
	if (l >= r) return 1;
	else if (str[l] != str[r]) return 0;

	return isPalindrome(l + 1, r - 1);
}

void func() {
	int ret = isPalindrome(0, str.size() - 1);
	cout << ret << ' ' << ans << '\n';
	ans = 0;
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