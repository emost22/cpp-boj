#include <iostream>
#include <string>
using namespace std;

const int cnt[] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
string str;

void func() {
	bool flag = false;
	for (auto x : str) {
		if (!(cnt[x - 'A'] & 1)) continue;
		flag = !flag;
	}

	if (flag) cout << "I'm a winner!\n";
	else cout << "You're the winner?\n";
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}