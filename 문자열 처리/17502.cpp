#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int l = 0;
	int r = N - 1;
	while (l <= r) {
		if (str[l] == '?' && str[r] == '?') {
			str[l] = str[r] = 'a';
		}
		else if (str[l] == '?') {
			str[l] = str[r];
		}
		else if (str[r] == '?') {
			str[r] = str[l];
		}
		l++;
		r--;
	}

	cout << str << '\n';
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