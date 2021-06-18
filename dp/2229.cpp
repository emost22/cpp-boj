#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int list[1000], dp[1000];
int N;

int func(int idx) {
	if (idx == N) return 0;

	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;

	int maxScore = list[idx];
	int minScore = list[idx];
	for (int i = idx; i < N; i++) {
		maxScore = max(maxScore, list[i]);
		minScore = min(minScore, list[i]);

		ret = max(ret, func(i + 1) + (maxScore - minScore));
	}

	return ret;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0) << '\n';

	return 0;
}