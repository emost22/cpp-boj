#include <iostream>
#include <string>
#include <cstring>
#define MAX 101
using namespace std;

string list[MAX];
int aCnt[26], bCnt[26];
int N, aLen, bLen;

bool cmpStr() {
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (aCnt[i] == bCnt[i]) continue;
		cnt += abs(aCnt[i] - bCnt[i]);
	}

	if (cnt > 2) return false;
	return true;
}

void func() {
	int ans = 0;
	for (int i = 1; i < N; i++) {
		bLen = list[i].size();
		if (abs(bLen - aLen) > 1) continue;

		for (int j = 0; j < bLen; j++) {
			bCnt[list[i][j] - 'A']++;
		}

		if (cmpStr()) {
			ans++;
		}
		memset(bCnt, 0, sizeof(bCnt));
	}

	cout << ans << '\n';
}

void init() {
	aLen = list[0].size();
	for (int i = 0; i < aLen; i++) {
		aCnt[list[0][i] - 'A']++;
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}