#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int N = str[str.size() - 1] - '0';

	if (N % 2) cout << "odd\n";
	else cout << "even\n";
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