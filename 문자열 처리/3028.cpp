#include <iostream>
#include <string>
using namespace std;

string str;
int ans[3];
int N;

void func() {
	ans[0] = 1;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'A') swap(ans[0], ans[1]);
		else if (str[i] == 'B') swap(ans[1], ans[2]);
		else swap(ans[0], ans[2]);
	}

	for (int i = 0; i < 3; i++) {
		if (ans[i]) {
			cout << i + 1 << '\n';
			return;
		}
	}
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}