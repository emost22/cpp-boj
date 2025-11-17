#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	char pre = '\0';
	for (auto x : str) {
		if (pre == x) continue;
		pre = x;
		cout << x;
	}
	cout << '\n';
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