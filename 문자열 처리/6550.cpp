#include <iostream>
#include <string>
#include <cstring>
#define MAX 100001
using namespace std;

string sub, str;
int N, M;

void func() {
	for (int i = 0, j = 0; i < N; i++) {
		if (str[i] == sub[j]) {
			if (j == M - 1) {
				cout << "Yes\n";
				return;
			}
			j++;
		}
	}

	cout << "No\n";
}

void input() {
	cin >> str;
	N = str.size();
	M = sub.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> sub) {
		input();
		func();
	}

	return 0;
}