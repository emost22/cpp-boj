#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string str;

void func() {
	string ans;
	istringstream ss(str);

	while (getline(ss, ans, ' ')) {
		reverse(ans.begin(), ans.end());
		cout << ans << ' ';
	}
	cout << '\n';
}

void input() {
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	getline(cin, str);
	while (tc--) {
		input();
		func();
	}

	return 0;
}