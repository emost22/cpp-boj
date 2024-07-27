#include <iostream>
#include <string>
using namespace std;

string str;
int N;

bool solve(int l, int r) {
	if (r == l) return true;

	int m = (l + r) >> 1;
	int s = (r - l + 1) >> 1;
	for (int i = 0; i < s; i++) {
		if (str[l + i] == str[r - i]) return false;
	}
	return solve(l, m - 1) & solve(m + 1, r);
}

void func() {
	if (solve(0, N - 1)) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> str;
	N = str.size();
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