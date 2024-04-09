#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;

void func() {
	string ret = "";
	while (N) {
		ret += ((N % 9) + '0');
		N /= 9;
	}
	reverse(ret.begin(), ret.end());

	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}