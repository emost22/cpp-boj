#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	for (int i = 0; i < N - 1; i++) {
		list[i] = list[i + 1] - list[i];
	}

	int x = list[0];
	for (int i = 1; i < N - 1; i++) {
		x = gcd(x, list[i]);
	}

	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans += (list[i] / x - 1);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}