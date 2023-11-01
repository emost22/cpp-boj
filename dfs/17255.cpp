#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
string str;
int N, len;

void dfs(int l, int r, string now) {
	if (N == now.size()) {
		s.insert(now);
		return;
	}

	if (l - 1 >= 0) {
		dfs(l - 1, r, now + str.substr(l - 1, r - l + 2));
	}
	if (r + 1 < len) {
		dfs(l, r + 1, now + str.substr(l , r - l + 2));
	}
}

void func() {
	for (int i = 0; i < len; i++) {
		string tmp = "";
		tmp += str[i];
		dfs(i, i, tmp);
	}

	cout << s.size() << '\n';
}

void input() {
	cin >> str;
	len = str.size();
	N = len * (len + 1) >> 1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}