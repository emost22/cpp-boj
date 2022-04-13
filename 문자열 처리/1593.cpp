#include <iostream>
#include <string>
#include <unordered_set>
#include <cstring>
#define MAX 52
using namespace std;

string str;
int wCnt[MAX], sCnt[MAX];
int N, M;

int charToInt(char x) {
	if ('a' <= x && x <= 'z') return x - 'a';
	else return x - 'A' + 26;
}

void func() {
	int ans = 0;
	int s = 0;
	for (int i = 0; i < M; i++) {
		int idx = charToInt(str[i]);
		if (sCnt[idx] >= wCnt[idx]) {
			for (int j = s; j <= i; j++) {
				int eraseIdx = charToInt(str[j]);
				if (str[i] == str[j]) {
					s = j + 1;
					break;
				}

				sCnt[eraseIdx]--;
			}
		}
		else sCnt[idx]++;

		if (i - s + 1 == N) ans++;
	}

	cout << ans << '\n';
}

void input() {
	string tmp;
	cin >> N >> M >> tmp >> str;
	for (int i = 0; i < N; i++) {
		wCnt[charToInt(tmp[i])]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}