#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int len = str.size();
	char x = str[0];
	for (int i = 1; i < len; i++) {
		if (x == str[i]) {
			cout << "No\n";
			return;
		}
		x = str[i];
	}

	cout << "Yes\n";
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}