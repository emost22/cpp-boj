#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int ret = 0;
	for (int i = 0; i < (N >> 1); i++) {
		ret += (list[i] << 1);
	}
	if (N & 1) ret += list[N >> 1];

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