#include <iostream>
#include <string>
#include <algorithm>
#define LEN 7
using namespace std;

string str;
int len;

void func() {
	sort(str.begin(), str.end());

	string bp = "BGIORVY";
	string sp = "bgiorvy";
	int bi = 0;
	int si = 0;
	for (int i = 0; i < len; i++) {
		if (bi < LEN && bp[bi] == str[i]) bi++;
		else if (si < LEN && sp[si] == str[i]) si++;
	}

	if (bi == LEN && si == LEN) cout << "YeS\n";
	else if (bi == LEN) cout << "YES\n";
	else if (si == LEN) cout << "yes\n";
	else cout << "NO!\n";
}

void input() {
	cin >> len >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}