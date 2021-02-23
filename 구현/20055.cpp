#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > list;
int N, K, ans;

void func() {
	for (int t = 1; ; t++) {
		list.insert(list.begin(), list[2 * N - 1]);
		list.pop_back();

		for (int i = N - 1; i >= 0; i--) {
			if (i == N - 1) {
				list[i].second = 0;
				continue;
			}
			if (!list[i].second) continue;
			if (!list[i + 1].first || list[i + 1].second) continue;

			if (i + 1 != N - 1) list[i + 1].second = 1;
			list[i].second = 0;
			list[i + 1].first--;

			if (!list[i + 1].first) ans++;
		}

		if (list[0].first) {
			list[0].second = 1;
			list[0].first--;
			if (!list[0].first) ans++;
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
		cin >> x;
		list.push_back({ x, 0 });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}