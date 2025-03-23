#include <iostream>
#include <string>
#include <algorithm>
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define MAX 4
using namespace std;

string str;

bool isContainsZero(int x) {
	while (x) {
		int y = x % 10;
		if (!y) return true;
		x /= 10;
	}
	return false;
}

int getClockNum(int x) {
	string s = to_string(x);
	int ret = x;

	FOR(i, 0, MAX - 2) {
		s += s[0];
		s = s.substr(1, s.size());
		ret = min(ret, stoi(s));
	}

	return ret;
}

void func() {
	int x = getClockNum(stoi(str));

	int ret = 0;
	FOR(i, 1111, x) {
		if (isContainsZero(i)) continue;
		if (getClockNum(i) != i) continue;
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	char x;
	FOR(i, 0, MAX - 1) {
		cin >> x;
		str += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}