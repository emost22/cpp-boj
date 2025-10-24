#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int ret = 0;
	string now = "";
	for (auto x : str) {
		if (x == ' ') {
			ret += (stoi(now) > 0);
			now = "";
		}
		else {
			now += x;
		}
	}
	ret += (stoi(now) > 0);

	cout << ret << '\n';
}

void input() {
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}