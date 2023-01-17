#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
typedef long long ll;

unordered_set<ll> s;
string str;
int len;

bool isOneAndZero(int n) {
	while (n) {
		if (n % 10 > 1) return false;
		n /= 10;
	}

	return true;
}

void addNum(string ssum) {
	ll ret = 0;
	ll sum = 0;
	int slen = ssum.size();
	for (int i = 0; i < slen; i++) {
		if (ssum[i] == '+') {
			ret += sum;
			sum = 0;
		}
		else sum = sum * 10 + ssum[i] - '0';
	}

	ret += sum;
	s.insert(ret);
}

void dfs(int idx, string sum) {
	if (idx == len) {
		addNum(sum);
		return;
	}

	dfs(idx + 1, sum + str[idx]);
	if (sum != "") dfs(idx + 1, sum + "+" + str[idx]);
}

void func() {
	if (isOneAndZero(stoi(str))) {
		cout << "Hello, BOJ 2023!\n";
		return;
	}

	dfs(0, "");
	ll num = stoll(str);
	ll ans = 0;
	for (int i = 1; ; i++) {
		ll ret = 0;
		for (int j = 0; j < len; j++) {
			int n = i;
			ll mul = 1;
			while (n--) {
				mul *= ((ll)str[j] - (ll)'0');
			}
			ret += mul;
		}

		if (num < ret) break;
		ans += (s.find(ret) != s.end());
	}
	cout << ans << '\n';
	s.clear();
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}