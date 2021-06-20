#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 1000000000
using namespace std;

typedef struct Point {
	int wt;
	int wm;
	int ct;
	int cm;
};

Point list[100];
int dp[100][100001];
int N, M;

int func(int idx, int sum) {
	if (sum > M) return -INF;
	if (idx == N) return 0;

	int &ret = dp[idx][sum];
	if (ret != -1) return ret;

	ret = max(func(idx + 1, sum + list[idx].ct) + list[idx].cm, func(idx + 1, sum + list[idx].wt) + list[idx].wm);

	return ret;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i].wt >> list[i].wm >> list[i].ct >> list[i].cm;
	}
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(0, 0) << '\n';

	return 0;
}