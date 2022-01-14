#include <iostream>
#include <string>
using namespace std;

int N;

bool dfs(int idx, string str) {
	for (int i = 1; i <= idx / 2; i++) {
		string l = str.substr(idx - i * 2, i);
		string r = str.substr(idx - i, i);

		if (l == r) return false;
	}

	if (idx == N) {
		cout << str << '\n';
		return true;
	}

	for (int i = 1; i <= 3; i++) {
		char next = i + '0';
		if (dfs(idx + 1, str + next)) return true;
	}

	return false;
}

void func() {
	string str = "";
	for (int i = 1; i <= 3; i++) {
		char x = i + '0';
		if (dfs(1, str + x)) return;
	}
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