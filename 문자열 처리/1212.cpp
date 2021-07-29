#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	string ans = "";
	string subAns = "";
	for (int i = 0; i < str.size(); i++) {
		int x = str[i] - '0';
		subAns.push_back((x / 4) + '0');
		x %= 4;

		subAns.push_back((x / 2) + '0');
		x %= 2;
		
		subAns.push_back(x + '0');

		if (ans == "") {
			if (subAns[0] == '0') {
				if (subAns[1] == '0') {
					if (subAns[2] == '0') {
						continue;
					}
					else ans += subAns[2];
				}
				else ans += subAns.substr(1, 2);
			}
			else ans += subAns;
		}
		else ans += subAns;

		subAns = "";
	}

	if (ans == "") cout << "0\n";
	else cout << ans << '\n';
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