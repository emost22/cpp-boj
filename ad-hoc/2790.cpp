#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	int maxValue = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i] + N >= maxValue);
		maxValue = max(maxValue, list[i] + i + 1);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
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