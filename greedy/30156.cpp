#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len;

void func() {
	int a = 0;
	for (int i = 0; i < len; i++) {
		a += (str[i] == 'a');
	}
	cout << min(a, len - a) << '\n';
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