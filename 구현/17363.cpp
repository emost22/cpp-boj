#include <iostream>
#define MAX 110
using namespace std;

char list[MAX][MAX];
int N, M;

char rotate(char x) {
	if (x == '-') return '|';
	if (x == '|') return '-';
	if (x == '/') return '\\';
	if (x == '\\') return '/';
	if (x == '^') return '<';
	if (x == '<') return 'v';
	if (x == 'v') return '>';
	if (x == '>') return '^';
	return x;
}

void func() {
	for (int j = M - 1; j >= 0; j--) {
		for (int i = 0; i < N; i++) {
			cout << rotate(list[i][j]);
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}