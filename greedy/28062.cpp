#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 0;
	int m = 1e9;
	for (int i = N - 1; i >= 0; i--) {
		if (list[i] & 1) m = min(m, list[i]);
		ret += list[i];
	}
	if (ret & 1) ret -= m;

	cout << ret << '\n';
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