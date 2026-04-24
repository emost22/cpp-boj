#include <iostream>
#include <string>
using namespace std;

string a, b;

bool isVowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

string getShortWord(string s) {
	string ret = "";
	bool chk = false;
	for (char x : s) {
		if (isVowel(x)) chk = true;
		else if (chk) break;

		ret += x;
	}

	return ret;
}

void func() {
	string ta = getShortWord(a);
	string tb = getShortWord(b);

	if (ta == a || tb == b) cout << "no such exercise\n";
	else cout << ta + tb << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}