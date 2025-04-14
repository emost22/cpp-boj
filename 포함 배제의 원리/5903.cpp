#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

typedef struct Node {
	int sx, sy, ex, ey;
}Node;

Node list[MAX];
int N;

Node getSameArea(Node node, int idx) {
	Node ret;
	ret.sx = max(node.sx, list[idx].sx);
	ret.sy = max(node.sy, list[idx].sy);
	ret.ex = min(node.ex, list[idx].ex);
	ret.ey = min(node.ey, list[idx].ey);
	return ret;
}

void func() {
	int ret = 0;
	for (int i = 1; i < (1 << N); i++) {
		int cnt = 0;
		Node node = { (int)-1e9,(int)-1e9,(int)1e9,(int)1e9 };
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].sx >> list[i].ey >> list[i].ex >> list[i].sy;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}