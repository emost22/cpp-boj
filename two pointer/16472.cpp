#include <iostream>
#include <algorithm>
#include <string>
#define MAX 100000
using namespace std;

string str;
int alpha[26];
int N;

void func() {
	int l = 0;
	int r = 1;
	int ans = 1;
	int len = 1;
	int cnt = 1;
	alpha[str[0] - 'a']++;
	
	while (r < str.size()) {
		if (!alpha[str[r] - 'a']) cnt++;
		alpha[str[r] - 'a']++;
		len++;

		while (cnt > N) {
			alpha[str[l] - 'a']--;
			if (!alpha[str[l] - 'a']) cnt--;
			l++;
			len--;
		}

		ans = max(ans, len);
		r++;
	}

	cout << ans << '\n';
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