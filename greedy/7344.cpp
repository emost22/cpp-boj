#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

pair<int, int> list[5000];
bool visit[5000];
int N, ans = 1, cnt = 1;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> list[i].first >> list[i].second;
		}
		sort(list, list + N);

		int now = 0;
		visit[now] = true;
		int length = list[0].first;
		int weight = list[0].second;
		while (1) {
			if (cnt == N) break;
			if (now < N - 1) now++;
			else {
				for (int i = 1; i < now; i++) {
					if (!visit[i]) {
						now = i;
						break;
					}
				}
				ans++;
				length = list[now].first;
				weight = list[now].second;
				visit[now] = true;
				cnt++;
				continue;
			}

			if (!visit[now] && length <= list[now].first && weight <= list[now].second) {
				cnt++;
				visit[now] = true;
				length = list[now].first;
				weight = list[now].second;
				continue;
			}
		}
		cout << ans << '\n';
		memset(visit, false, sizeof(visit));
		ans = 1;
		cnt = 1;
	}

	return 0;
}