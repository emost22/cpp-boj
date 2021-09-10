#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;

int list[MAX + 1], maxTree[(MAX + 1) * 4], minTree[(MAX + 1) * 4];
int N, M;

int maxInit(int node, int s, int e) {
	if (s == e) {
		return maxTree[node] = list[s];
	}

	int m = (s + e) / 2;
	return maxTree[node] = max(maxInit(node * 2, s, m), maxInit(node * 2 + 1, m + 1, e));
}

void maxUpdate(int node, int s, int e, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		maxTree[node] = diff;
		return;
	}

	int m = (s + e) / 2;
	maxUpdate(node * 2, s, m, idx, diff);
	maxUpdate(node * 2 + 1, m + 1, e, idx, diff);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
}

int maxQuery(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return maxTree[node];

	int m = (s + e) / 2;
	return max(maxQuery(node * 2, s, m, l, r), maxQuery(node * 2 + 1, m + 1, e, l, r));
}

int minInit(int node, int s, int e) {
	if (s == e) {
		return minTree[node] = list[s];
	}

	int m = (s + e) / 2;
	return minTree[node] = min(minInit(node * 2, s, m), minInit(node * 2 + 1, m + 1, e));
}

void minUpdate(int node, int s, int e, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		minTree[node] = diff;
		return;
	}

	int m = (s + e) / 2;
	minUpdate(node * 2, s, m, idx, diff);
	minUpdate(node * 2 + 1, m + 1, e, idx, diff);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
}

int minQuery(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return MAX + 1;
	if (l <= s && e <= r) return minTree[node];

	int m = (s + e) / 2;
	return min(minQuery(node * 2, s, m, l, r), minQuery(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int type, x, y;
	while (M--) {
		cin >> type >> x >> y;
		if (type == 1) {
			maxUpdate(1, 1, N, list[x], y);
			minUpdate(1, 1, N, list[x], y);
			maxUpdate(1, 1, N, list[y], x);
			minUpdate(1, 1, N, list[y], x);
			swap(list[x], list[y]);
		}
		else {
			int minValue = minQuery(1, 1, N, x, y);
			int maxValue = maxQuery(1, 1, N, x, y);

			if (maxValue - minValue == y - x) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		list[i] = x;
		maxUpdate(1, 1, N, list[i], i);
		minUpdate(1, 1, N, list[i], i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}