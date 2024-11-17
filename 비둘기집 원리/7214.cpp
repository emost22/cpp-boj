#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N, k;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += min(list[i], k - 1);
	}
	cout << ret + 1 << '\n';
}

void input() {
	cin >> k >> N;
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