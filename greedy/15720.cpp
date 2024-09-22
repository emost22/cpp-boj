#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[3][MAX];
int N, M, K;

void func() {
	sort(list[0], list[0] + N, [](int a, int b) {
		return a > b;
	});
	sort(list[1], list[1] + M, [](int a, int b) {
		return a > b;
	});
	sort(list[2], list[2] + K, [](int a, int b) {
		return a > b;
	});

	int sum = 0;
	int ret = 0;
	int r = min(N, min(M, K));
	for (int i = 0; i < r; i++) {
		sum += (list[0][i] + list[1][i] + list[2][i]);
	}
	ret = sum * 0.9;

	for (int i = r; i < N; i++) {
		sum += list[0][i];
		ret += list[0][i];
	}

	for (int i = r; i < M; i++) {
		sum += list[1][i];
		ret += list[1][i];
	}

	for (int i = r; i < K; i++) {
		sum += list[2][i];
		ret += list[2][i];
	}

	cout << sum << '\n' << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[0][i];
	}

	for (int i = 0; i < M; i++) {
		cin >> list[1][i];
	}

	for (int i = 0; i < K; i++) {
		cin >> list[2][i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}