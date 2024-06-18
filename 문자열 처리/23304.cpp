#include <iostream>
#include <string>
using namespace std;

string str;
int len;

bool isPalindrome(int l, int r) {
	while (l < r) {
		if (str[l++] != str[r--]) return false;
	}
	return true;
}

bool isAkaraka(int l, int r) {
	if (l == r) return true;
	if (!isPalindrome(l, r)) return false;
	if ((r - l + 1) & 1) return isAkaraka(l, ((l + r + 1) >> 1) - 1) && isAkaraka(((l + r + 1) >> 1) + 1, r);
	return isAkaraka(l, ((l + r + 1) >> 1) - 1) && isAkaraka(((l + r + 1) >> 1), r);
}

void func() {
	if (isAkaraka(0, len - 1)) cout << "AKARAKA\n";
	else cout << "IPSELENTI\n";
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