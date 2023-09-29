#include <iostream>
#include <algorithm>
#define MAX_N 10000
#define MAX_M 10
using namespace std;

int endTime[MAX_M];
int list[MAX_N];
int N, M;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	for (int i = 0; i < N; i++) {
		int idx = 0;
		int minValue = endTime[0];
		for (int j = 1; j < M; j++) {
			if (minValue > endTime[j]) {
				idx = j;
				minValue = endTime[j];
			}
		}

		endTime[idx] += list[i];
	}

	int ret = 0;
	for (int i = 0; i < M; i++) {
		if (!endTime[i]) continue;
		ret = max(ret, endTime[i]);
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