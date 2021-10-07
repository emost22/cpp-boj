#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N;

void func() {
	for (int i = 0; i < N - 1; i++) {
		if (str[i] < str[i + 1]) {
			reverse(str.begin(), str.begin() + i + 1);
			reverse(str.begin(), str.begin() + i + 2);
		}
	}

	reverse(str.begin(), str.end());

	cout << str << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}