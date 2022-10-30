#include <iostream>
#include <string>
#define MAX 101
using namespace std;

string str[MAX];
int N;

char getLower(char x) {
	if ('A' <= x && x <= 'Z') return x + 32;
	else return x;
}

void func() {
	for (int i = 0; i < N; i++) {
		int len = str[i].size();
		for (int j = 0; j < len; j++) {
			cout << getLower(str[i][j]);
		}
		cout << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}