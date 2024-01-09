#include <iostream>
#define MAX 31
using namespace std;

int N;

void func() {
	for (int i = 1; i <= N; i++) {
		if (MAX % (i + 1) == 1) cout << i << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}