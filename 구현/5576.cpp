#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int w[MAX], k[MAX];

void func() {
	sort(w, w + MAX, [](int a, int b) {
		return a > b;
	});
	sort(k, k + MAX, [](int a, int b) {
		return a > b;
	});

	cout << w[0] + w[1] + w[2] << ' ' << k[0] + k[1] + k[2] << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < MAX; i++) {
		cin >> k[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}