#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007
using namespace std;

vector<int> graph[8];
int dp[8][100001];
int N;

void init() {
	graph[0].push_back(1); graph[0].push_back(2);
	graph[1].push_back(0); graph[1].push_back(2); graph[1].push_back(3);
	graph[2].push_back(0); graph[2].push_back(1); graph[2].push_back(3); graph[2].push_back(6);
	graph[3].push_back(1); graph[3].push_back(2); graph[3].push_back(4); graph[3].push_back(6);
	graph[4].push_back(3); graph[4].push_back(5); graph[4].push_back(6);
	graph[5].push_back(4); graph[5].push_back(7);
	graph[6].push_back(2); graph[6].push_back(3); graph[6].push_back(4); graph[6].push_back(7);
	graph[7].push_back(5); graph[7].push_back(6);
}

int func(int idx, int cnt) {
	if (cnt == N) {
		if(!idx) return 1;
		return 0;
	}

	int &ret = dp[idx][cnt];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];

		ret = (ret + func(next, cnt + 1)) % MOD;
	}

	return ret;
}

void input() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	cout << func(0, 0) << '\n';

	return 0;
}