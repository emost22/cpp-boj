#include <iostream>
#include <algorithm>
#define MAX 20000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int l = 0;
	int r = N - 1;
	int ans = 0;
	while (l < r) {
		int sum = list[l] + list[r];

		if (sum <= M) ans += (r - l);

		if (sum > M) r--;
		else l++;
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