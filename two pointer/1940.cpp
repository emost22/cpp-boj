#include <iostream>
#include <algorithm>
#define MAX 15000
using namespace std;

int list[MAX];
int N, M;

void func() {
	int ans = 0;
	int l = 0;
	int r = N - 1;
	while (l < r) {
		int sum = list[l] + list[r];

		if (sum >= M) {
			if (sum == M) ans++;
			r--;
		}
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