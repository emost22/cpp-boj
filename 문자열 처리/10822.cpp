#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string str;

void func() {
	int ans = 0;
	string nstr;
	istringstream ss(str);
	while (getline(ss, nstr, ',')) {
		ans += stoi(nstr);
	}

	cout << ans << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}