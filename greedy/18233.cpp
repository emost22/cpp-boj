#include <iostream>
#include <vector>
#define MAX 21
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int ret[MAX];
int N, P, E;

bool dfs(int idx, int cnt, int mn, int mx, vector<int> tmp) {
	if (mn > E) return false;
	if (cnt == P) {
		if (E > mx) return false;

		int r = E - mn;
		for (auto x : tmp) {
			ret[x] = list[x].first;
			if (!r) continue;
			int t = min(r, list[x].second - list[x].first);
			r -= t;
			ret[x] += t;
		}

		return true;
	}

	for (int i = idx; i < N; i++) {
		tmp.push_back(i);
		if (dfs(i + 1, cnt + 1, mn + list[i].first, mx + list[i].second, tmp)) return true;
		tmp.pop_back();
	}

	return false;
}

void func() {
	bool flag = false;
	vector<int> tmp;
	for (int i = 0; i < N; i++) {
		tmp.push_back(i);
		flag |= dfs(i + 1, 1, list[i].first, list[i].second, tmp);
		if (flag) break;
		tmp.pop_back();
	}

	if (!flag) {
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		cout << ret[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> P >> E;
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