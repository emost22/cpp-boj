#include <iostream>
#include <string>
#define KLEN 5
#define YLEN 6
using namespace std;

string pat[2] = { "KOREA", "YONSEI" };
string str;
int len;

void func() {
	int k = 0;
	int y = 0;
	for (int i = 0; i < len; i++) {
		if (pat[0][k] == str[i]) k++;
		if (pat[1][y] == str[i]) y++;

		if (k == KLEN) {
			cout << pat[0] << '\n';
			return;
		}

		if (y == YLEN) {
			cout << pat[1] << '\n';
			return;
		}
	}
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}