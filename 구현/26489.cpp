#include <iostream>
#include <string>
using namespace std;

void input() {
	string str;
	int ret = 0;
	while (getline(cin, str)) {
		ret++;
	}

	cout << ret << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}