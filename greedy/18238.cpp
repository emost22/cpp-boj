#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N;

void func() {
	int ans = 0;
	char x = 'A';
	for (int i = 0; i < N; i++) {
		ans += min(abs(x - str[i]), 26 - abs(x - str[i]));
		x = str[i];
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