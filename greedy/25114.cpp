#include <iostream>
#define MAX 1000001
using namespace std;

int a[MAX], b[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N - 1; i++) {
		if (a[i] == b[i]) continue;

		ret++;
		a[i + 1] ^= (a[i] ^ b[i]);
	}

	if (a[N - 1] != b[N - 1]) ret = -1;
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}