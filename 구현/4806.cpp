#include <iostream>
#include <string>
using namespace std;

string str;
int ret;

void func() {
	cout << ret << '\n';
}

void input() {
	while (getline(cin, str)) {
		ret++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}