#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N - 1; i++) {
		ret += (str[i] == 'E' && str[i + 1] == 'W');
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}