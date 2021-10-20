#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int l = 0;
	int r = 0;
	int ans = 2e9;
	while (l <= r && r < N) {
		if (list[r] - list[l] >= M) {
			ans = min(ans, list[r] - list[l]);
			l++;
		}
		else r++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}