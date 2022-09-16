#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;

int maxTree[MAX * 4], minTree[MAX * 4];
int list[MAX];
int N, M;

void init(int node, int s, int e) {
	if (s == e) {
		maxTree[node] = minTree[node] = list[s];
		return;
	}

	int m = (s + e) >> 1;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
}

int maxQuery(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return maxTree[node];

	int m = (s + e) >> 1;
	return max(maxQuery(node * 2, s, m, l, r), maxQuery(node * 2 + 1, m + 1, e, l, r));
}

int minQuery(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 1e9;
	if (l <= s && e <= r) return minTree[node];

	int m = (s + e) >> 1;
	return min(minQuery(node * 2, s, m, l, r), minQuery(node * 2 + 1, m + 1, e, l, r));
}

void func() {
	int l, r;
	while (M--) {
		cin >> l >> r;
		cout << maxQuery(1, 1, N, l, r) - minQuery(1, 1, N, l, r) << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
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