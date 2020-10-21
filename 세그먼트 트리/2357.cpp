#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int list[100001], maxtree[400004], mintree[400004];
int N, M;

int maxinit(int s, int e, int node) {
	if (s == e) {
		return maxtree[node] = list[s];
	}

	int m = (s + e) / 2;
	return maxtree[node] = max(maxinit(s, m, node * 2), maxinit(m + 1, e, node * 2 + 1));
}

int mininit(int s, int e, int node) {
	if (s == e) {
		return mintree[node] = list[s];
	}

	int m = (s + e) / 2;
	return mintree[node] = min(mininit(s, m, node * 2), mininit(m + 1, e, node * 2 + 1));
}

int maxdiv(int s, int e, int l, int r, int node) {
	if (l <= s && e <= r) return maxtree[node];
	if (e < l || s > r) return -INF;

	int m = (s + e) / 2;
	return max(maxdiv(s, m, l, r, node * 2), maxdiv(m + 1, e, l, r, node * 2 + 1));
}

int mindiv(int s, int e, int l, int r, int node) {
	if (l <= s && e <= r) return mintree[node];
	if (e < l || s > r) return INF;

	int m = (s + e) / 2;
	return min(mindiv(s, m, l, r, node * 2), mindiv(m + 1, e, l, r, node * 2 + 1));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	maxinit(1, N, 1);
	mininit(1, N, 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		cout << mindiv(1, N, a, b, 1) << ' ' << maxdiv(1, N, a, b, 1) << '\n';
	}

	return 0;
}