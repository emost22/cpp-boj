#include <iostream>
#include <string>
#include <algorithm>
#define MAX 11
using namespace std;
typedef long long ll;

string str;
ll cnt[MAX];
int len;

void init() {
	cnt[0] = 1;
	cnt[1] = 26LL;
	for (int i = 2; i < MAX; i++) {
		cnt[i] = cnt[i - 1] * 26LL;
	}
}

void func() {
	init();

	reverse(str.begin(), str.end());
	ll ret = 0;
	for (int i = 0; i < len; i++) {
		ret += (cnt[i] * (str[i] - 'A' + 1));
	}
	cout << ret << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}