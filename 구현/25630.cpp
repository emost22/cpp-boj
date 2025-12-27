#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int l = 0;
	int r = N - 1;
	int ret = 0;
	while (l < r) {
		ret += (str[l++] != str[r--]);
	}

	cout << ret << '\n';
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