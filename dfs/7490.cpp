#include <iostream>
#include <string>
using namespace std;

int list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int N;
//' ', +, -
void func(int idx, string str) {
	if (idx == N) {
		int ans = 0;
		int now = 0;
		char op = 0;
		for (int i = 0; i < str.size(); i++) {
			if ('0' <= str[i] && str[i] <= '9') {
				now = now * 10 + str[i] - '0';
			}
			else {
				if (str[i] == ' ') continue;
				
				if (op == '+' || op == 0) {
					ans += now;
				}
				else {
					ans -= now;
				}

				now = 0;
				op = str[i];
			}
		}

		if (op == '+' || op == 0) {
			ans += now;
		}
		else {
			ans -= now;
		}

		if (!ans) cout << str << '\n';
		return;
	}

	func(idx + 1, str + (" " + to_string(list[idx])));
	func(idx + 1, str + ("+" + to_string(list[idx])));
	func(idx + 1, str + ("-" + to_string(list[idx])));
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func(1, to_string(list[0]));
		if (tc) cout << '\n';
	}

	return 0;
}