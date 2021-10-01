#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

void func() {
	int N = str.size();
	int zeroCnt = str[0] == '0' ? 1 : 0;
	int oneCnt = str[0] == '1' ? 1 : 0;
	int conn = 1;
	for (int i = 1; i < N; i++) {
		if (str[i] == str[i - 1]) {
			conn++;
			continue;
		}

		if (str[i] == '1') oneCnt++;
		else zeroCnt++;
		conn = 1;
	}

	cout << min(zeroCnt, oneCnt) << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}