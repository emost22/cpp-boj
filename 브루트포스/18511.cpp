#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

int list[MAX];
int N, K, ret;

void solve(int sum) {
	if (sum > N) return;
	ret = max(ret, sum);

	for (int i = 0; i < K; i++) {
		solve(sum * 10 + list[i]);
	}
}

void func() {
	solve(0);
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
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