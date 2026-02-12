#include <iostream>
#define MAX 32769
using namespace std;

bool chk[MAX];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		if (chk[i]) continue;

		cout << i << '\n';
		return;
	}
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
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