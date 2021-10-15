#include <iostream>
#include <algorithm>
#define MAX 300000
using namespace std;

int list[MAX], diff[MAX];
int N, K, ans;

void func() {
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