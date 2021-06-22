#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1234567
using namespace std;

vector<int> graph[10];
int dp[10][1001];
int N;

int func(int idx, int len) {
	int &ret = dp[idx][len];
	
	if (len == N) return ret = 1;
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];

		ret = (ret + func(next, len + 1)) % MOD;
	}

	return ret;
}

void init() {
	graph[0].push_back(7);
	graph[1].push_back(2); graph[1].push_back(4);
	graph[2].push_back(1); graph[2].push_back(3); graph[2].push_back(5);
	graph[3].push_back(2); graph[3].push_back(6);
	graph[4].push_back(1); graph[4].push_back(5); graph[4].push_back(7);
	graph[5].push_back(2); graph[5].push_back(4); graph[5].push_back(6); graph[5].push_back(8);
	graph[6].push_back(3); graph[6].push_back(5); graph[6].push_back(9);
	graph[7].push_back(0); graph[7].push_back(4); graph[7].push_back(8);
	graph[8].push_back(5); graph[8].push_back(7); graph[8].push_back(9);
	graph[9].push_back(6); graph[9].push_back(8);
}

void input() {
	int ans = 0;
	cin >> N;
	for (int i = 0; i < 10; i++) {
		ans = (ans + func(i, 1)) % MOD;
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc;
	cin >> tc;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		input();
	}

	return 0;
}