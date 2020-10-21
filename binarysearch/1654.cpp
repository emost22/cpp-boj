#include <iostream>
using namespace std;

long long int len[10000], max_len, length;
int sum, K, N;

long long int Max(long long int x, long long int y) {
	return x > y ? x : y;
}

void binarysearch(long long int s, long long int e) {
	if (s > e) return;

	long long int m = (s + e) / 2;
	if (!m) m = 1;

	for (int i = 0; i < K; i++) {
		sum += len[i] / m;
	}

	if (sum >= N) {
		sum = 0;
		length = Max(length, m);
		binarysearch(m + 1, e);
	}
	else {
		sum = 0;
		binarysearch(s, m - 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> len[i];
		max_len = Max(max_len, len[i]);
	}

	binarysearch(0, max_len);

	cout << length << '\n';

	return 0;
}