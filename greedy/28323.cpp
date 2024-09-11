#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;

int list[MAX];
int N;

int solve(int t) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if ((list[i] & 1) == t) {
			ret++;
			t = 1 - t;
		}
	}
	return ret;
}

void func() {
	cout << max(solve(0), solve(1)) << '\n';
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