#include <iostream>
#include <string>
using namespace std;

string str;
int N;

int func() {
	int idx = 0;
	while (idx < N) {
		int len = 0;
		while (idx < N && str[idx] == 'w') {
			len++;
			idx++;
		}
		if (!len) return 0;

		for (int i = 0; i < len; i++) {
			if (idx == N || str[idx] != 'o') return 0;
			idx++;
		}

		for (int i = 0; i < len; i++) {
			if (idx == N || str[idx] != 'l') return 0;
			idx++;
		}

		for (int i = 0; i < len; i++) {
			if (idx == N || str[idx] != 'f') return 0;
			idx++;
		}
	}

	return 1;
}

void input() {
	cin >> str;
	N = str.size();

	cout << func() << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}