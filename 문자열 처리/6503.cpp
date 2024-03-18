#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 128
using namespace std;

string str;
int ch[MAX];
int N, len;

void func() {
	int l = 0;
	int r = 0;
	int cnt = 0;
	int ret = 0;
	while (r < len) {
		if (!ch[str[r]]) cnt++;

		ch[str[r]]++;
		if (cnt > N) {
			while (cnt > N) {
				ch[str[l]]--;
				if (!ch[str[l]]) cnt--;
				l++;
			}
		}

		ret = max(ret, r - l + 1);
		r++;
	}

	cout << ret << '\n';
	memset(ch, 0, sizeof(ch));
}

void input() {
	getline(cin, str);
	N = stoi(str);
	if (!N) exit(0);

	getline(cin, str);
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}