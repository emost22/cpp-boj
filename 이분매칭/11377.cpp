#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define MAX 1001
using namespace std;

ifstream in("in.inp");

vector<int> list[MAX];
int work[MAX];
bool chk[MAX];
int N, M, K, ans, cnt;

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

	int P, v;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> P;

		for (int j = 0; j < P; j++) {
			cin >> v;
			list[i].push_back(v);
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(chk + 1, chk + 1 + M, false);
		if (dfs(i)) ans++;
	}

	for (int i = 1; i <= N; i++) {
		fill(chk + 1, chk + 1 + M, false);
		if (dfs(i)) {
			ans++;
			K--;
			if (!K) break;
		}
	}

	cout << ans << '\n';

	return 0;
}