#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int list[MAX], diff[MAX];
int N, K;

void func() {
	if (N <= K) {
		cout << "0\n";
		return;
	}

	int ans = 0;
	for (int i = 0; i < N - K; i++) {
		ans += diff[i];
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);

	for (int i = 0; i < N - 1; i++) {
		diff[i] = list[i + 1] - list[i];
	}
	sort(diff, diff + N - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}