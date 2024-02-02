#include <iostream>
#include <string>
#define MAX 101
using namespace std;

string str[MAX];
int N;

char getLower(char x) {
	if ('a' <= x && x <= 'z') return x;
	return x + 32;
}

bool isVowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

void func() {
	for (int i = 0; i < N; i++) {
		int vowelCnt = 0;
		int consonantCnt = 0;
		for (auto x : str[i]) {
			if (x == ' ') continue;

			char ch = getLower(x);
			if (isVowel(ch)) {
				vowelCnt++;
			}
			else {
				consonantCnt++;
			}
		}

		cout << consonantCnt << ' ' << vowelCnt << '\n';
	}
}

void input() {
	string n;
	getline(cin, n);
	N = stoi(n);
	for (int i = 0; i < N; i++) {
		getline(cin, str[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}