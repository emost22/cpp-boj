#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int list[MAX];
int N, M;

void func() {
	int ans = 0;
	int m = 0;
	for (int i = 0; i <= N; i++) {
		if (!list[i]) {
			m = i;
			break;
		}
	}

	for (int i = 0; i < m; i += M) {
		ans += (-list[i] * 2);
	}

	for (int i = N; i >= m; i -= M) {
		ans += (list[i] * 2);
	}

	ans -= max(abs(list[0]), abs(list[N]));

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N + 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}