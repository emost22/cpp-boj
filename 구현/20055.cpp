#include <iostream>
#include <vector>
using namespace std;

pair<int, int> list[201];
int N, K, ans;

void func() {
	int l = 1;
	int r = N;
	for (int t = 1; ; t++) {
		l--;
		r--;
		if (!l) l = 2 * N;
		if (!r) r = 2 * N;

		for (int i = r; ; i--) {
			if (!i) i = 2 * N;
			if (i == r) {
				list[i].second = 0;
				continue;
			}
			int next = i + 1;
			if (next == 2 * N + 1) next = 1;
			
			if (!list[i].second) {
				if (i == l) break;
				continue;
			}
			if (!list[next].first || list[next].second) {
				if (i == l) break;
				continue;
			}

			if (next != r) list[next].second = 1;
			list[i].second = 0;
			list[next].first--;

			if (!list[next].first) ans++;
			
			if (i == l) break;
		}

		if (list[l].first) {
			list[l].second = 1;
			list[l].first--;
			if (!list[l].first) ans++;
		}

		if (ans >= K) {
			cout << t << '\n';
			break;
		}
	}
}

void input() {
	int x;
	cin >> N >> K;
	for (int i = 1; i <= 2 * N; i++) {
		cin >> list[i].first;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}