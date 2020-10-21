#include <iostream>
using namespace std;
typedef long long ll;

int N, M;
ll list[1025][1025], tree[1025][1025];

void update(int x, int y, ll diff) {
	for (int i = x; i <= N; i += (i & -i)) {
		for (int j = y; j <= N; j += (j & -j)) {
			tree[i][j] += diff;
		}
	}
}

ll sum(int x, int y) {
	ll ans = 0;

	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) {
			ans += tree[i][j];
		}
	}

	return ans;
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
			update(i, j, list[i][j]);
		}
	}

	int w, x, y;
	while (M--) {
		cin >> w;
		if (!w) {
			ll c;

			cin >> x >> y >> c;
			update(x, y, c - list[x][y]);
			list[x][y] = c;
		}
		else {
			int x2, y2;

			cin >> x >> y >> x2 >> y2;
			ll ans = 0;

			cout << sum(x2, y2) - sum(x2, y - 1) - sum(x - 1, y2) + sum(x - 1, y - 1) << '\n';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}