#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int l, r;
	while (M--) {
		cin >> l >> r;
		int x = lower_bound(list, list + N, l) - list;
		int y = upper_bound(list, list + N, r) - list;

		cout << y - x << '\n';
	}
}

void input() {
	cin >> N >> M;
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