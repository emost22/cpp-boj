#include <iostream>
#include <string>
using namespace std;

string str;
int K, len;

void func() {
	for (int i = 0; i < len; i += K) {
		cout << str[i];
	}
	cout << '\n';
}

void input() {
	cin >> K >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}