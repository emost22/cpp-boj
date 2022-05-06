#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int idx = 0;
	for (int x = 1; ; x++) {
		string tmp = to_string(x);
		int len = tmp.size();
		for (int i = 0; i < len; i++) {
			if (tmp[i] == str[idx]) {
				idx++;
				if (idx == N) {
					cout << x << '\n';
					return;
				}
			}
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