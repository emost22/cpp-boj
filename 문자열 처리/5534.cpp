#include <iostream>
#define MAX 101
using namespace std;

string list[MAX];
string str;
int N, len;

bool isPossibleUse(string s) {
	int ssize = s.size();
	for (int l = 0; l <= ssize - len; l++) {
		if (s[l] != str[0]) continue;
		for (int r = ssize - 1; r - l + 1 >= len; r--) {
			if (s[r] != str[len - 1]) continue;
			if ((r - l) % (len - 1)) continue;

			int diff = (r - l) / (len - 1);
			bool flag = true;
			for (int i = l, j = 0; i <= r; i += diff, j++) {
				if (s[i] != str[j]) {
					flag = false;
					break;
				}
			}

			if (flag) return true;
		}
	}

	return false;
}

void func() {
	int ret = 0;
	for (auto s : list) {
		ret += isPossibleUse(s);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
	len = str.size();
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}