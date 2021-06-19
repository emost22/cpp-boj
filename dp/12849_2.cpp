#include <iostream>
#include <vector>
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

void func() {
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int next = graph[j][k];
				dp[j][i] = (dp[j][i] + dp[next][i - 1]) % MOD;
			}
		}
	}

	cout << dp[0][N] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}