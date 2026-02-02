#include <iostream>
#define WEEK 7
using namespace std;

int N, M;

void func() {
	if (N > WEEK) cout << N - WEEK << '\n';
	else cout << M + WEEK << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}