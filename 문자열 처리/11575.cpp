#include <iostream>
#include <string>
#define MOD 26
using namespace std;

string str;
int a, b;

void func() {
	for (int i = 0; i < str.size(); i++) {
		cout << (char)((a * (str[i] - 'A') + b) % MOD + 'A');
	}
	cout << '\n';
}

void input() {
	cin >> a >> b >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}