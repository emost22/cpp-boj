#include <iostream>
#include <algorithm>
#define MAX 251
using namespace std;

int maxTree[MAX][MAX * 4], minTree[MAX][MAX * 4];
int list[MAX][MAX];
int N, B, Q;

void init(int node, int s, int e) {
	if (s == e) {
		for (int i = 1; i <= N; i++) {
			maxTree[i][node] = minTree[i][node] = list[i][s];
		}
		return;
	}

	int m = (s + e) >> 1;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	for (int i = 1; i <= N; i++) {
		maxTree[i][node] = max(maxTree[i][node * 2], maxTree[i][node * 2 + 1]);
		minTree[i][node] = min(minTree[i][node * 2], minTree[i][node * 2 + 1]);
	}
}

int maxQuery(int idx, int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return maxTree[idx][node];

	int m = (s + e) >> 1;
	return max(maxQuery(idx, node * 2, s, m, l, r), maxQuery(idx, node * 2 + 1, m + 1, e, l, r));
}

int minQuery(int idx, int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 1e9;
	if (l <= s && e <= r) return minTree[idx][node];

	int m = (s + e) >> 1;
	return min(minQuery(idx, node * 2, s, m, l, r), minQuery(idx, node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int x, y;
	while (Q--) {
		cin >> x >> y;
		int maxValue = 0;
		int minValue = 1e9;
		for (int i = x; i < x + B; i++) {
			maxValue = max(maxValue, maxQuery(i, 1, 1, N, y, y + B - 1));
			minValue = min(minValue, minQuery(i, 1, 1, N, y, y + B - 1));
		}

		cout << maxValue - minValue << '\n';
	}
}

void input() {
	cin >> N >> B >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
		}
	}
	init(1, 1, N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}