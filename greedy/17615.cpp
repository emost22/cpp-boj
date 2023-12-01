#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N;

void func() {
	int bCnt = 0;
	int rCnt = 0;
	bool bFlag = false;
	bool rFlag = false;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'B') {
			bFlag = true;
			bCnt += rFlag;
		}
		if (str[i] == 'R') {
			rFlag = true;
			rCnt += bFlag;
		}
	}

	int ret = min(bCnt, rCnt);
	bCnt = 0;
	rCnt = 0;
	bFlag = false;
	rFlag = false;
	for (int i = N - 1; i >= 0; i--) {
		if (str[i] == 'B') {
			bFlag = true;
			bCnt += rFlag;
		}
		if (str[i] == 'R') {
			rFlag = true;
			rCnt += bFlag;
		}
	}

	ret = min(ret, min(bCnt, rCnt));
	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}