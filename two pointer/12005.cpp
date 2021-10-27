#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int list[MAX];
int N, K;

void func() {
	int l = 0;
	int r = 0;
	int ans = 0;
	while (r < N) {
		if (list[r] - list[l] > K) {
			l++;
		}
		else {
			ans = max(ans, r - l + 1);
			r++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
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