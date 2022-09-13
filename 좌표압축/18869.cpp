#include <iostream>
#include <algorithm>
#define MAXN 101
#define MAXM 10001
using namespace std;
typedef pair<int, int> pii;

pii list[MAXN][MAXM];
int N, M;

void func() {
	for (int i = 0; i < N; i++) {
		int pre = -1;
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			if (pre != list[i][j].first) ++cnt;
			pre = list[i][j].first;
			list[i][j].first = cnt;
		}
		sort(list[i], list[i] + M, [](pii a, pii b) {
			return a.second < b.second;
		});
	}

	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			bool flag = true;
			for (int k = 0; k < M; k++) {
				if (list[i][k].first != list[j][k].first) {
					flag = false;
					break;
				}
			}

			if (flag) ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j].first;
			list[i][j].second = j;
		}
		sort(list[i], list[i] + M);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}