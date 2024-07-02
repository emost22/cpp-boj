#include <iostream>
#include <algorithm>
#define MAX 10010
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (!list[i]) continue;
		int cnt = list[i];
		list[i] = 0;
		ret += (3 * cnt);

		if (i + 1 >= N) continue;
		cnt = min(cnt, list[i + 1]);
		list[i + 1] -= cnt;
		ret += (2 * cnt);

		if (i + 2 >= N) continue;
		if (cnt + list[i + 1] > list[i + 2]) {
			cnt = min(cnt, max(0, list[i + 2] - list[i + 1]));
		}
		list[i + 2] -= cnt;
		ret += (2 * cnt);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
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