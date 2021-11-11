#include <iostream>
#define MAX 300000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = N;
	for (int i = N - 1; i >= 0; i--) {
		if (list[i] == ans) ans--;
	}

	cout << ans << '\n';
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