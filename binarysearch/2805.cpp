#include <iostream>
using namespace std;

long long int sum;
int height[1000000], max_height, ans;

int Max(int x, int y) {
	return x > y ? x : y;
}

void binarysearch(long long int x, int n, int s, int e) {
	if (s > e) return;

	int m = (s + e) / 2;

	for (int i = 0; i < n; i++) {
		if (height[i] > m) {
			sum += height[i] - m;
		}
	}

	if (sum >= x) {
		sum = 0;
		if (ans < m) {
			ans = m;
		}
		binarysearch(x, n, m + 1, e);
	}
	else {
		sum = 0;
		binarysearch(x, n, s, m - 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	long long int M;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> height[i];
		max_height = Max(max_height, height[i]);
	}
	binarysearch(M, N, 0, max_height);
	cout << ans << '\n';

	return 0;
}