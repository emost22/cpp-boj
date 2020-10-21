#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

vector<pair<int, int> > list[MAX];
int book[MAX];
bool chk[MAX];
int N, M, ans;

bool dfs(int x) {
	for (int i = list[x][0].first; i <= list[x][0].second; i++) {
		int y = i;
		if (chk[y]) continue;
		chk[y] = true;

		if (book[y] == 0 || dfs(book[y])) {
			book[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int testcase, a, b;
	cin >> testcase;
	while (testcase--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> a >> b;
			list[i].push_back({ a,b });
		}

		for (int i = 1; i <= M; i++) {
			fill(chk, chk + MAX, false);
			if (dfs(i)) ans++;
		}

		cout << ans << '\n';
		ans = 0;
		for (int i = 1; i <= M; i++) list[i].clear();
		fill(book, book + MAX, 0);
	}

	return 0;
}