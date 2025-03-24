#include <iostream>
#define YEAR 365
#define MONTH 13
using namespace std;

int days[MONTH] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int sy, sm, sd, ey, em, ed;

bool isGg() {
	if (sy + 1000 < ey) return true;
	else if (sy + 1000 == ey) {
		if (sm < em) return true;
		else if (sm == em) return sd <= ed;
		return false;
	}
	return false;
}

bool isLeapYear(int y) {
	if (!(y % 400)) return true;
	else if (!(y % 4) && (y % 100)) return true;
	return false;
}

int getDays(int y, int m, int d) {
	int ret = 0;
	for (int i = 1; i < y; i++) {
		ret += (YEAR + isLeapYear(i));
	}

	for (int i = 1; i < m; i++) {
		if (i == 2 && isLeapYear(y)) ret++;
		ret += days[i];
	}

	return ret + d;
}

void func() {
	if (isGg()) {
		cout << "gg\n";
		return;
	}

	int s = getDays(sy, sm, sd);
	int e = getDays(ey, em, ed);

	cout << "D-" << e - s << '\n';
}

void input() {
	cin >> sy >> sm >> sd >> ey >> em >> ed;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}