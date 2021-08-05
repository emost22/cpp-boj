#include <iostream>
#include <string>
using namespace std;

string str;

void input() {
	cin >> str;
	cout << str[0] << str[str.size() - 1] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}