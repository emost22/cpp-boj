#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N;

void noAnswer() {
	cout << "-1\n";
	exit(0);
}

void func() {
	if (N & 1) noAnswer();

	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == '(') {
			cnt++;
		}
		else {
			cnt--;
		}

		ret = max(ret, abs(cnt));
	}

	if (cnt) noAnswer();

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