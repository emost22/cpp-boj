#include <iostream>
#include <string>
using namespace std;

void input() {
	string str;
	while (getline(cin, str)) {
		cout << str << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}