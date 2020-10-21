#include <iostream>
#include <cstring>
using namespace std;

int tree[200002], pos[100001], N, M, now;

void update(int idx, int diff) {
	while (idx <= N + M) {
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

int query(int idx) {
	int ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= (idx & -idx);
	}

	return ans;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N >> M;
		now = M;
		for (int i = M + 1; i <= N + M; i++) {
			update(i, 1);
			pos[i - M] = i;
		}
		for (int i = 0; i < M; i++) {
			int x;
			cin >> x;
			cout << query(pos[x] - 1) << ' ';
			update(pos[x], -1);
			update(now, 1);
			pos[x] = now;
			now--;
		}
		cout << '\n';

		memset(tree, 0, sizeof(tree));
		memset(pos, 0, sizeof(pos));
	}

	return 0;
}