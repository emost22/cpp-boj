#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int ret = 0;
	int bonus = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'O') {
			ret += (i + 1 + bonus);
			bonus++;
		}
		else {
			bonus = 0;
		}
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