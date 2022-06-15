#include <iostream>
#define MAX 31
using namespace std;

bool chk[MAX];
int N;

void func() {
	for (int i = 1; i < MAX; i++) {
		if (!chk[i]) {
			cout << i << '\n';
		}
	}
}

void input() {
	int x;
	N = 28;
	for (int i = 0; i < N; i++) {
		cin >> x;
		chk[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}