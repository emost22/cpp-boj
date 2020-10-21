#include <iostream>
using namespace std;

int list[122], dp[300001];
int N;

int Min(int x, int y) {
	return x < y ? x : y;
}

void init() {
	int a = 3;
	int p = 3;
	list[1] = 1;
	for (int i = 2; ; i++) {
		list[i] = list[i - 1] + a;
		a += p;
		p++;
		if (list[i] > N) break;
	}
}

int find() {
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
	}

	for (int i = 2; list[i + 1]; i++) {
		for (int j = 1; j <= N; j++) {
			if (list[i] <= j) dp[j] = Min(dp[j], dp[j - list[i]] + 1);
		}
	}

	return dp[N];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	init();
	cout << find() << '\n';

	return 0;
}