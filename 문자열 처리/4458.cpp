#include <iostream>
#include <string>
using namespace std;

string str;

void input() {
	getline(cin, str);
	if ('a' <= str[0] && str[0] <= 'z') str[0] -= 32;
	cout << str << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	string x;
	cin >> tc;
	getline(cin, x);
	while (tc--) {
		input();
	}

	return 0;
}