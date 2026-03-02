#include <iostream>
#define MAX 200000
using namespace std;

int list[MAX];
int N, M, V;

void func() {
	int x;
	while (M--) {
		cin >> x;

		if (x < N) cout << list[x] << '\n';
		else cout << list[(x - V) % (N - V) + V] << '\n';
	}
}

void input() {
	cin >> N >> M >> V;
	V--;
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