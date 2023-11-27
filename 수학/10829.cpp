#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll N;

void func() {
	string str = "";
	while (N) {
		if (N & 1) str = "1" + str;
		else str = "0" + str;
		N >>= 1;
	}

	cout << str << '\n';
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