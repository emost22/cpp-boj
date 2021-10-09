#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i % 3 != 2) ans += list[i];
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	sort(list, list + N, [](int a, int b) {
		return a > b;
	});
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}