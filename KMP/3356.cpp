#include <iostream>
#include <string>
#define MAX 1000001
using namespace std;

string str;
int fail[MAX];
int N;

void func() {
	for (int i = 1, j = 0; i < N; i++) {
		while (j > 0 && str[i] != str[j]) j = fail[j - 1];

		if (str[i] == str[j]) {
			fail[i] = ++j;
		}
	}

	cout << N - fail[N - 1] << '\n';
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