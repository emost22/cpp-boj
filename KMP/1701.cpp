#include <iostream>
#include <string>
#include <cstring>
#define MAX 5001
using namespace std;

string str;
int failMove[MAX];
int N;

void makeFail(string subStr) {
	int len = subStr.size();
	memset(failMove, 0, sizeof(failMove));
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && subStr[i] != subStr[j]) {
			j = failMove[j - 1];
		}

		if (subStr[i] == subStr[j]) {
			failMove[i] = ++j;
		}
	}
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		string subStr = str.substr(i, N);
		makeFail(subStr);
		for (int j = 0; j < N; j++) {
			ans = max(ans, failMove[j]);
		}
	}

	cout << ans << '\n';
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