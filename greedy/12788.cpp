#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX];
int N, M, k;

void func() {
	for (int i = 0; i < N; i++) {
		M -= list[i];
		if (M <= 0) {
			cout << i + 1 << '\n';
			return;
		}
	}

	cout << "STRESS\n";
}

void input() {
	cin >> N >> M >> k;
	M *= k;
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