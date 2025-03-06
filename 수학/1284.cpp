#include <iostream>
#include <string>
using namespace std;

string N;

void func() {
	int ret = 1;
	for (auto x : N) {
		if (x == '1') ret += 3;
		else if (x == '0') ret += 5;
		else ret += 4;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		if (N == "0") break;

		func();
	}

	return 0;
}