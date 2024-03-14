#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 26
using namespace std;

string a, b;
int cnt[MAX];

void func() {
	string ret = "";
	for (auto x : a) {
		cnt[x - 'a']++;
	}

	for (auto x : b) {
		if (!cnt[x - 'a']) continue;

		ret += x;
		cnt[x - 'a']--;
	}

	sort(ret.begin(), ret.end());
	cout << ret << '\n';
	memset(cnt, 0, sizeof(cnt));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (getline(cin, a) && getline(cin, b)) {
		func();
	}

	return 0;
}