#include <iostream>
#include <algorithm>
#define MAX 5
using namespace std;

char list[MAX][2];

bool isSameColor() {
	return list[0][0] == list[1][0] && list[1][0] == list[2][0] && list[2][0] == list[3][0] && list[3][0] == list[4][0];
}

int chkStraight(char *c) {
	for (int i = 1; i < MAX; i++) {
		if (c[i] - c[i - 1] != 1) return 0;
	}
	return c[MAX - 1] - '0';
}

int chkSameFourCards(char* c) {
	if (c[0] == c[3]) return c[0] - '0';
	else if (c[1] == c[4]) return c[1] - '0';
	return 0;
}

int chkThreeTwo(char* c) {
	if (c[0] != c[1] || c[3] != c[4]) return 0;
	if (c[1] == c[2]) return (c[0] - '0') * 10 + c[4] - '0' + 700;
	else if (c[2] == c[3]) return (c[4] - '0') * 10 + c[0] - '0' + 700;
	return 0;
}

int chkThree(char* c) {
	for (int i = 2; i < MAX; i++) {
		if (c[i - 2] == c[i - 1] && c[i - 1] == c[i]) return c[i] - '0';
	}
	return 0;
}

int chkTwoTwo(char* c) {
	int mx = 0;
	int mn = 0;
	for (int i = 1; i < MAX; i++) {
		if (c[i - 1] != c[i]) continue;
		if (!mx) mx = c[i] - '0';
		else mn = c[i] - '0';
	}
	if (mn > mx) swap(mn, mx);

	if (!mn) return 0;
	return mx * 10 + mn + 300;
}

int chkTwo(char* c) {
	for (int i = 1; i < MAX; i++) {
		if (c[i - 1] != c[i]) continue;
		return c[i] - '0' + 200;
	}
	return 0;
}

void func() {
	char* tmp = new char[] { list[0][1], list[1][1], list[2][1], list[3][1], list[4][1] };
	sort(tmp, tmp + MAX);

	int st = chkStraight(tmp);
	int fc = chkSameFourCards(tmp);
	int tht = chkThreeTwo(tmp);
	int th = chkThree(tmp);
	int ttwo = chkTwoTwo(tmp);
	int two = chkTwo(tmp);
	if (isSameColor() && st) cout << st + 900 << '\n';
	else if (fc) cout << fc + 800 << '\n';
	else if (tht) cout << tht << '\n';
	else if (isSameColor()) cout << tmp[4] - '0' + 600 << '\n';
	else if (st) cout << st + 500 << '\n';
	else if (th) cout << th + 400 << '\n';
	else if (ttwo) cout << ttwo << '\n';
	else if (two) cout << two << '\n';
	else cout << tmp[4] - '0' + 100 << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i][0] >> list[i][1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}