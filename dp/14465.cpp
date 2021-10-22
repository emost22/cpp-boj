#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, K, B;

void func() {
	for (int i = 1; i <= N; i++) {
		list[i] += list[i - 1];
	}

	int ans = 1e6;
	for (int i = K; i <= N; i++) {
		ans = min(ans, list[i] - list[i - K]);
	}

	cout << ans << '\n';
}

void input() {
	int x;
	cin >> N >> K >> B;
	for (int i = 1; i <= B; i++) {
		cin >> x;
		list[x] = 1;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}