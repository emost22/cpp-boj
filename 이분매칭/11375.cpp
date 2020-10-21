#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector<int> list[MAX];
int work[MAX];
bool chk[MAX];
int N, M, ans;

bool dfs(int x) {
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (chk[y]) continue;
		chk[y] = true;

		if (work[y] == 0 || dfs(work[y])) {
			work[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int K, v;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> v;
			list[i].push_back(v);
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(chk + 1, chk + 1 + N, false);
		if (dfs(i)) ans++;
	}

	cout << ans << '\n';

	return 0;
}