#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> v1, v2;
int list[4][MAX];
int N, K;

int binarySearch(int x) {
	int ret = 1e9;
	int l = 0;
	int r = N * N - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		int sum = x + v2[m];
		
		if (sum == K) return K;
		else if (sum < K) l = m + 1;
		else r = m - 1;

		int re = abs(K - ret);
		int s = abs(K - sum);
		if (re >= s) {
			if (re == s) ret = min(ret, sum);
			else ret = sum;
		}
	}

	return ret;
}

void func() {
	int ans = 1e9;
	for (int i = 0; i < N * N; i++) {
		int sum = binarySearch(v1[i]);

		if (sum == K) {
			ans = K;
			break;
		}

		int a = abs(K - ans);
		int b = abs(K - sum);
		if (a >= b) {
			if (a == b) ans = min(ans, sum);
			else ans = sum;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> K >> N;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v1.push_back((list[0][i] + list[1][j]));
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v2.push_back((list[2][i] + list[3][j]));
		}
	}
	sort(v2.begin(), v2.end());
}

void init() {
	v1.clear();
	v2.clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}