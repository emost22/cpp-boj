#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N, K;

void func() {
	cout << list[K - 1] << '\n';
}

void input() {
	cin >> N >> K;
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