#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int list[MAX];
int N, K;

void func() {
	int l = 0;
	int r = N - 1;
	int ans = 2e8;
	int cnt = 0;
	while (l < r) {
		int sum = list[l] + list[r];
		if (abs(sum - K) < abs(ans - K)) {
			ans = sum;
			cnt = 1;
		}
		else if (abs(sum - K) == abs(ans - K)) {
			cnt++;
		}

		if (sum > K) r--;
		else l++;
	}

	cout << cnt << '\n';
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}