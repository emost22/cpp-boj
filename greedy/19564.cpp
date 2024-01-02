#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int ret = 1;
	for (int i = 1; i < N; i++) {
		ret += (str[i - 1] >= str[i]);
	}

	cout << ret << '\n';
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