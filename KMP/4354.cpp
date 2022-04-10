#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 1000001
using namespace std;

string str;
int failMove[MAX];
int N;

void func() {
	memset(failMove, 0, sizeof(failMove));
	int ans = 0;
	int j = 0;
	for (int i = 1; i < N; i++) {
		if (j > 0 && str[i] != str[j]) {
			j = failMove[j - 1];
		}

		if (str[i] == str[j]) {
			failMove[i] = ++j;
		}
	}

	if (N % (N - failMove[N - 1])) cout << "1\n";
	else cout << N / (N - failMove[N - 1]) << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		if (str == ".") return 0;

		func();
	}
}