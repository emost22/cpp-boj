#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string str;

void func() {
	sort(str.begin(), str.end(), [](char a, char b) {
		return a > b;
	});
	cout << stoll(str.substr(0, str.size() - 1)) + stoll(str.substr(str.size() - 1, 1)) << '\n';
}

void input() {
	cin >> str;
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