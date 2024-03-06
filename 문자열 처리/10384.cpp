#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 26
using namespace std;

int cnt[MAX];
string str;
int len;

char getLowercase(char x) {
	if ('A' <= x && x <= 'Z') return x + 32;
	return x;
}

bool isAlpha(char x) {
	return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
}

void func(int tc) {
	for (int i = 0; i < len; i++) {
		if (!isAlpha(str[i])) continue;
		char x = getLowercase(str[i]);
		cnt[x - 'a']++;
	}

	int minCnt = 3;
	for (int i = 0; i < MAX; i++) {
		minCnt = min(minCnt, cnt[i]);
	}

	if (minCnt == 3) {
		cout << "Case " << tc << ": Triple pangram!!!\n";
	}
	else if (minCnt == 2) {
		cout << "Case " << tc << ": Double pangram!!\n";
	}
	else if (minCnt == 1) {
		cout << "Case " << tc << ": Pangram!\n";
	}
	else {
		cout << "Case " << tc << ": Not a pangram\n";
	}

	memset(cnt, 0, sizeof(cnt));
}

void input() {
	getline(cin, str);
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	getline(cin, str);
	int tc = stoi(str);
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}