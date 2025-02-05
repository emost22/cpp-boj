#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX];
int N, M;

void func() {
	int* suf = new int[N];
	suf[N - 1] = list[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		suf[i] = max(suf[i + 1], list[i]);
	}

	int ret = list[N - 1] - list[0];
	for (int i = 0; i <= M; i++) {
		ret = max(ret, suf[N - 1 - M + i] - list[i]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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