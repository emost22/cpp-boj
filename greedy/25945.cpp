#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, sum;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int x = sum / N;
	int m = sum % N;
	int ret = 0;
	for (int i = 0; i < m; i++) {
		if (list[i] <= x + 1) break;
		ret += (list[i] - (x + 1));
	}

	for (int i = m; i < N; i++) {
		if (list[i] <= x) break;
		ret += (list[i] - x);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		sum += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}