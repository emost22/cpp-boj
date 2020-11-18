#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	string str;
	cin >> tc;
	while (tc--) {
		cin >> str;
		cout << str[0] + str[2] - '0' - '0' << '\n';
	}

	return 0;
}
