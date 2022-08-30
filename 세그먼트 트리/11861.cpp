#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

int tree[MAX * 4];
ll list[MAX], ans;
int N;

void init(int node, int s, int e) {
	if (s == e) {
		tree[node] = s;
		return;
	}

	int m = (s + e) / 2;
	init(node * 2, s, m);
	init(node * 2 + 1, m + 1, e);
	tree[node] = list[tree[node * 2]] < list[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1];
}

int query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return -1;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	int leftIdx = query(node * 2, s, m, l, r);
	int rightIdx = query(node * 2 + 1, m + 1, e, l, r);
	if (leftIdx == -1) return rightIdx;
	else if (rightIdx == -1) return leftIdx;
	else return list[leftIdx] < list[rightIdx] ? leftIdx : rightIdx;
}

void partition(int s, int e) {
	if (s > e) return;

	int idx = query(1, 1, N, s, e);
	ans = max(ans, (1LL * e - s + 1) * (list[idx]));
	partition(s, idx - 1);
	partition(idx + 1, e);
}

void func() {
	partition(1, N);
	cout << ans << '\n';
}

void input() {
	cin >> N;
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