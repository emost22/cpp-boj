#include <iostream>
#include <string>
#include <algorithm>
#define MAX 500001
using namespace std;

string str;
int N;

void func() {
	int ans = -1;
	bool flag = false;
	int l = 0;
	int r = N - 1;
	while (l < r) {
		if (str[l] != str[r]) {
			ans = N;
			break;
		}
		if (str[l] != str[l + 1]) flag = true;
		l++;
		r--;
	}

	if (flag && ans == -1) ans = N - 1;
	cout << ans << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}