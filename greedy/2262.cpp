#include <iostream>
#include <algorithm>
#define MAX 256
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = N; i > 1; i--) {
		int j = 0;
		for (; j <= N; j++) {
			if (i == list[j]) break;
		}

		ans += (i - max(list[j - 1], list[j + 1]));

		for (; j < N; j++) {
			list[j] = list[j + 1];
		}
		N--;
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