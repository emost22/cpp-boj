#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;
typedef long long ll;

ll list[2][MAX];

void func() {
	sort(list[0], list[0] + MAX, [](int a, int b) {
		return a > b;
	});
	sort(list[1], list[1] + MAX, [](int a, int b) {
		return a > b;
	});

	ll ret = 0;
	for (int i = 0; i < MAX; i++) {
		ret += (list[0][i] * list[1][i]);
	}
	cout << ret << '\n';
}

void input() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> list[i][j];
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