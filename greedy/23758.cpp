#include <iostream>
#include <algorithm>
#define MAX 2000001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	N = (N + 1) >> 1;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		while (list[i] != 1) {
			ret++;
			list[i] >>= 1;
		}
	}
	cout << ret + 1 << '\n';
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