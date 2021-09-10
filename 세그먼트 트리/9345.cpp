#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX], maxTree[MAX * 4], minTree[MAX * 4];
int N, K;

int maxInit(int node, int s, int e) {
	if (s == e) {
		return maxTree[node] = s;
	}

	int m = (s + e) / 2;
	return maxTree[node] = max(maxInit(node * 2, s, m), maxInit(node * 2 + 1, m + 1, e));
}

int minInit(int node, int s, int e) {
	if (s == e) {
		return minTree[node] = s;
	}

	int m = (s + e) / 2;
	return minTree[node] = min(minInit(node * 2, s, m), minInit(node * 2 + 1, m + 1, e));
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

int maxQuery(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return -1;
	if (l <= s && e <= r) return maxTree[node];

	int m = (s + e) / 2;
	return max(maxQuery(node * 2, s, m, l, r), maxQuery(node * 2 + 1, m + 1, e, l, r));
}

int minQuery(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return MAX;
	if (l <= s && e <= r) return minTree[node];

	int m = (s + e) / 2;
	return min(minQuery(node * 2, s, m, l, r), minQuery(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int type, x, y;
	while (K--) {
		cin >> type >> x >> y;
		if (type) {
			int minValue = minQuery(1, 0, N - 1, x, y);
			int maxValue = maxQuery(1, 0, N - 1, x, y);

			if (minValue == x && maxValue == y) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			swap(list[x], list[y]);
			maxUpdate(1, 0, N - 1, x, list[x]);
			minUpdate(1, 0, N - 1, x, list[x]);
			maxUpdate(1, 0, N - 1, y, list[y]);
			minUpdate(1, 0, N - 1, y, list[y]);
		}
	}
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		list[i] = i;
	}
	maxInit(1, 0, N - 1);
	minInit(1, 0, N - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}