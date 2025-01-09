#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int N;

int move(char x, char y) {
	return min(y - x, 26 + x - y);
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += move(min(a[i], b[i]), max(a[i], b[i]));
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}