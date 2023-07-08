#include <iostream>
#define MAX 101
using namespace std;

int list[MAX];
int N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int l, r, x;
	cin >> N >> M;
	while (M--) {
		cin >> l >> r >> x;
		for (int i = l; i <= r; i++) {
			list[i] = x;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}