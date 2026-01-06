#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int o = 0;
	int e = 0;
	for (int i = 0; i < len; i++) {
		if ((str[i] - '0') & 1) o++;
		else e++;
	}

	if (o > e) cout << "1\n";
	else if (o < e) cout << "0\n";
	else cout << "-1\n";
}

void input() {
	cin >> len >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}