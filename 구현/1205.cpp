#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

int list[MAX];
int N, P, x;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int ret = 1;
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		if (list[i] >= x) {
			if (list[i] > x) ret++;
			cnt++;
		}
	}
	if (cnt > P) ret = -1;

	cout << ret << '\n';
}

void input() {
	cin >> N >> x >> P;
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