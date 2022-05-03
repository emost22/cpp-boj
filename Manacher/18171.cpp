#include <iostream>
#include <string>
#include <algorithm>
#define MAX 800002
using namespace std;

string str;
int palindrome[MAX];
int N, M;

void manacher() {
	int p = 0;
	int r = 0;
	for (int i = 0; i < M; i++) {
		if (i <= r) palindrome[i] = min(palindrome[p * 2 - i], r - i);
		else palindrome[i] = 0;

		while (i - palindrome[i] - 1 >= 0 && i + palindrome[i] + 1 < M && str[i - palindrome[i] - 1] == str[i + palindrome[i] + 1]) palindrome[i]++;

		if (r < i + palindrome[i]) {
			r = i + palindrome[i];
			p = i;
			if (r == M - 1) {
				cout << N - palindrome[i] << '\n';
				return;
			}
		}
	}
}

void input() {
	string tmp;
	cin >> N >> tmp;
	for (int i = 0; i < N; i++) {
		str += '#';
		str += tmp[i];
	}
	str += '#';
	M = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	manacher();

	return 0;
}