#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
typedef pair<int, int> pi;

pi list[MAX * MAX];
int cnt[MAX];
int N, M;

void func() {
	int l = 0;
	int r = 0;
	int ans = 1e9;
	int num = 0;
	while (r < N * M) {
		if (!cnt[list[r].second]) num++;
		cnt[list[r].second]++;
		r++;

		while (num == N) {
			ans = min(ans, list[r - 1].first - list[l].first);

			cnt[list[l].second]--;
			if (!cnt[list[l].second]) num--;
			l++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N * M; i++) {
		cin >> list[i].first;
		list[i].second = i / M;
	}
	sort(list, list + N * M);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}