#include <iostream>
#define MAX 100000
using namespace std;

char list[MAX];
int N;

void func() {
	int x = 0;
	int y = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] == 'D') x++;
		else y++;

		if (x + 2 == y || x == y + 2) break;
	}

	cout << x << ':' << y << '\n';
}

void input() {
	cin >> N;
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