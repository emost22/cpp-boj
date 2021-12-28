#include <iostream>
#include <algorithm>
#include <string>
#define MAX 100
using namespace std;

int list[MAX];
int N, idx;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int ans = 0;
	for (int i = 0; i < idx - 1; i++) {
		for (int j = i + 1; j < idx; j++) {
			ans = max(ans, gcd(list[i], list[j]));
		}
	}

	cout << ans << '\n';
}

void input() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			idx++;
		}
		else {
			list[idx] = list[idx] * 10 + str[i] - '0';
		}
	}
	idx++;
}

void init() {
	for (int i = 0; i < idx; i++) list[i] = 0;
	idx = 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	string str;
	getline(cin, str);
	tc = stoi(str);
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}