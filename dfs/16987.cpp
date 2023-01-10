#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, ans;

int getBrokenCnt(int bit) {
	int ret = 0;
	while (bit) {
		ret += (bit & 1);
		bit >>= 1;
	}

	return ret;
}

void dfs(int idx, int bit) {
	ans = max(ans, getBrokenCnt(bit));
	if (ans == N) return;
	if (idx >= N) {
		return;
	}
	if (bit & (1 << idx)) {
		dfs(idx + 1, bit);
		return;
	}

	int nb = bit;
	for (int i = 0; i < N; i++) {
		if (bit & (1 << i)) continue;
		if (idx == i) continue;
		
		list[idx].first -= list[i].second;
		list[i].first -= list[idx].second;

		if (list[idx].first <= 0) {
			nb |= (1 << idx);
		}
		if (list[i].first <= 0) {
			nb |= (1 << i);
		}

		dfs(idx + 1, nb);
		list[idx].first += list[i].second;
		list[i].first += list[idx].second;
		nb = bit;
	}
}

void func() {
	dfs(0, 0);
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}