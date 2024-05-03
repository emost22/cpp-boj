#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	for (int i = 1; i < len; i++) {
		if ((str[i - 1] == 'D' || str[i - 1] == 'd') && str[i] == '2') {
			cout << "D2\n";
			return;
		}
	}
	cout << "unrated\n";
}

void input() {
	getline(cin, str);
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}