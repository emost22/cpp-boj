#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	string tmp = "";
	double x = -1.0;
	for (auto s : str) {
		if (s == '@') x *= 3.0;
		else if (s == '%') x += 5.0;
		else if (s == '#') x -= 7.0;
		else if (s == ' ') {
			if (x < 0) x = stod(tmp);
		}
		else tmp += s;
	}

	cout << fixed; cout.precision(2);
	cout << x << '\n';
}

void input() {
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	int tc;
	getline(cin, s);
	tc = stoi(s);
	while (tc--) {
		input();
		func();
	}

	return 0;
}