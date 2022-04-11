#include <iostream>
#include <algorithm>
#include <string>
#define MAX 200001
using namespace std;

string a, b, ans;
int fail[MAX];
int len;

bool solve(string str) {
	int n = str.size();
	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && str[i] != ans[j]) {
			j = fail[j - 1];
		}

		if (str[i] == ans[j]) {
			if (j == len - 1) return true;
			j++;
		}
	}

	return false;
}

void makeFail() {
	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && ans[i] != ans[j]) {
			j = fail[j - 1];
		}

		if (ans[i] == ans[j]) {
			fail[i] = ++j;
		}
	}
}

void func() {
	makeFail();

	if (solve(a) && solve(b)) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> a >> b >> ans;
	len = ans.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}