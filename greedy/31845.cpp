#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX];
int N, M;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int ret = 0;
	int removed = 0;
	for (int i = 0; i < N - removed; i++) {
		if (list[i] <= 0 || removed == M) break;

		ret += list[i];
		removed++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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