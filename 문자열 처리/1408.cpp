#include <iostream>
#include <string>
using namespace std;

string s, e;

void func() {
	int sh = (s[0] - '0') * 10 + s[1] - '0';
	int sm = (s[3] - '0') * 10 + s[4] - '0';
	int ss = (s[6] - '0') * 10 + s[7] - '0';
	int eh = (e[0] - '0') * 10 + e[1] - '0';
	int em = (e[3] - '0') * 10 + e[4] - '0';
	int es = (e[6] - '0') * 10 + e[7] - '0';

	int rs = es - ss;
	int rm = em - sm;
	int rh = eh - sh;
	if (rs < 0) {
		rs += 60;
		rm--;
	}

	if (rm < 0) {
		rm += 60;
		rh--;
	}

	if (rh < 0) {
		rh += 24;
	}

	string ret = "";
	ret += rh / 10 + '0';
	ret += rh % 10 + '0';
	ret += ':';
	ret += rm / 10 + '0';
	ret += rm % 10 + '0';
	ret += ':';
	ret += rs / 10 + '0';
	ret += rs % 10 + '0';

	cout << ret << '\n';
}

void input() {
	cin >> s >> e;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}