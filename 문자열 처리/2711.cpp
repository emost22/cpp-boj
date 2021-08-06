#include <iostream>
#include <string>
using namespace std;

string str;
int x;

void input() {
	cin >> x >> str;

	str.erase(str.begin() + x - 1);
	cout << str << '\n';
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