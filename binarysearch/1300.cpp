#include <iostream>
using namespace std;

int N, K, ans;

long long Min(long long x, long long y) {
	return x < y ? x : y;
}

long long binarysearch(int s, int e) {
	if (s > e) return ans;

	long long cnt = 0;
	int m = (s + e) / 2;
	
	for (int i = 1; i <= N; i++) {
		cnt += Min(m / i, N);
	}

	if (cnt < K) {
		return binarysearch(m + 1, e);
	}
	else {
		ans = m;
		return binarysearch(s, m - 1);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	cout << binarysearch(1, K) << '\n';

	return 0;
}