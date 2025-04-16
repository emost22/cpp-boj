#include <iostream>
#define MAX 3
using namespace std;
typedef long long ll;

typedef struct Node {
	ll sx, sy, ex, ey;
}Node;

Node list[MAX];
int N, W, H;

Node getXy(ll n, ll s, ll e, ll w) {
	return { w, n, W - e, H - s };
}

Node getSameArea(Node node, int idx) {
	Node ret;
	ret.sx = max(node.sx, list[idx].sx);
	ret.sy = max(node.sy, list[idx].sy);
	ret.ex = min(node.ex, list[idx].ex);
	ret.ey = min(node.ey, list[idx].ey);
	return ret;
}

void func() {
	ll ret = 0;
	for (int i = 1; i < (1 << N); i++) {
		int cnt = 0;
		Node node = { 0, 0, (ll)1e9, (ll)1e9 };
		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			cnt++;
			node = getSameArea(node, j);
		}
		if (node.sx > node.ex || node.sy > node.ey) continue;

		if (cnt & 1) ret += ((node.ex - node.sx) * (node.ey - node.sy));
		else ret -= ((node.ex - node.sx) * (node.ey - node.sy));
	}
	cout << ret << '\n';
}

void input() {
	ll n, s, e, w;
	cin >> N >> W >> H;
	for (int i = 0; i < N; i++) {
		cin >> n >> s >> e >> w;
		list[i] = getXy(n, s, e, w);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}