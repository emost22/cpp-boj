#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int bCnt = 0;
	int rCnt = 0;
	for (int i = 1; i <= N; i++) {
		if (str[i - 1] == str[i]) continue;

		if (str[i] == 'B') bCnt++;
		else rCnt++;
	}

	cout << min(bCnt, rCnt) + 1 << '\n';
}

void input() {
	cin >> N >> str;
	str = " " + str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}