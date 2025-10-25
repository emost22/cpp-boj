#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int pre = -1e9;
	int now;
	string tmp = "";
	for (auto x : str) {
		if (x == ' ') {
			now = stoi(tmp);
			if (pre > now) {
				cout << "Bad\n";
				return;
			}
			pre = now;
			tmp = "";
		}
		else {
			tmp += x;
		}
	}

	if (pre > stoi(tmp)) cout << "Bad\n";
	else cout << "Good\n";
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