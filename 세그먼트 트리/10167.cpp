#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 3001
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

typedef struct Point {
	int x, y;
	ll w;
}Point;

typedef struct Node {
	ll l, r, max, sum;
}Node;

Point list[MAX];
Node tree[MAX * 4];
vector<pil> yList[MAX];
pii xtmp[MAX], ytmp[MAX];
int N;

void update(int node, int s, int e, int idx, ll diff) {
	if (idx < s || idx > e) return;
	if (s == e) {
		tree[node].l += diff;
		tree[node].r += diff;
		tree[node].max += diff;
		tree[node].sum += diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = { max(tree[node * 2].l, tree[node * 2].sum + tree[node * 2 + 1].l), max(tree[node * 2 + 1].r, tree[node * 2 + 1].sum + tree[node * 2].r), max(max(tree[node * 2].max, tree[node * 2 + 1].max), tree[node * 2].r + tree[node * 2 + 1].l), tree[node * 2].sum + tree[node * 2 + 1].sum };
}

Node query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return { (int)-1e9, (int)-1e9, (int)-1e9, 0 };
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	Node leftNode = query(node * 2, s, m, l, r);
	Node rightNode = query(node * 2 + 1, m + 1, e, l, r);
	return { max(leftNode.l, leftNode.sum + rightNode.l), max(rightNode.r, rightNode.sum + leftNode.r), max(max(leftNode.max, rightNode.max), leftNode.r + rightNode.l), leftNode.sum + rightNode.sum };
}

void func() {
	sort(xtmp + 1, xtmp + 1 + N);
	sort(ytmp + 1, ytmp + 1 + N);

	int pre = 1e9 + 1;
	int xCnt = 0;
	for (int i = 1; i <= N; i++) {
		if (pre != xtmp[i].first) xCnt++;
		pre = xtmp[i].first;
		list[xtmp[i].second].x = xCnt;
	}

	pre = 1e9 + 1;
	int yCnt = 0;
	for (int i = 1; i <= N; i++) {
		if (pre != ytmp[i].first) yCnt++;
		pre = ytmp[i].first;
		list[ytmp[i].second].y = yCnt;
	}

	for (int i = 1; i <= N; i++) {
		yList[list[i].y].push_back({ list[i].x, list[i].w });
	}

	ll ans = -1e9 - 1;
	for (int i = 1; i <= yCnt; i++) {
		memset(tree, 0, sizeof(tree));
		for (int j = i; j <= yCnt; j++) {
			for (int k = 0; k < yList[j].size(); k++) {
				update(1, 1, N, yList[j][k].first, yList[j][k].second);
			}
			ans = max(ans, query(1, 1, N, 1, N).max);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].x >> list[i].y >> list[i].w;
		xtmp[i] = { list[i].x, i };
		ytmp[i] = { list[i].y, i };
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}