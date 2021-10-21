#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<int> lCnt, rCnt;
string str;
int N;

void func() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'K') cnt++;
		else lCnt.push_back(cnt);
	}

	cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (str[i] == 'K') cnt++;
		else rCnt.push_back(cnt);
	}
	reverse(rCnt.begin(), rCnt.end());

	int l = 0;
	int r = rCnt.size() - 1;
	int ans = 0;
	while (l <= r) {
		ans = max(ans, r - l + 1 + 2 * min(lCnt[l], rCnt[r]));

		if (lCnt[l] < rCnt[r]) l++;
		else r--;
	}

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