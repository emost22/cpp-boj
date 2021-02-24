#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> list[100];
int N, M, K, direct, dis;

void func() {
	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (direct == list[i].first) ans += abs(dis - list[i].second);
		else {
			if (direct == 1) {
				if (list[i].first == 2) {
					ans += min(M + dis + list[i].second, M + N - dis + N - list[i].second);
				}
				else if (list[i].first == 3) {
					ans += (dis + list[i].second);
				}
				else {
					ans += (N - dis + list[i].second);
				}
			}
			else if (direct == 2) {
				if (list[i].first == 1) {
					ans += min(M + dis + list[i].second, M + N - dis + N - list[i].second);
				}
				else if (list[i].first == 3) {
					ans += (dis + M - list[i].second);
				}
				else {
					ans += (N - dis + M - list[i].second);
				}
			}
			else if (direct == 3) {
				if (list[i].first == 1) {
					ans += (dis + list[i].second);
				}
				else if (list[i].first == 2) {
					ans += (N - dis + list[i].second);
				}
				else {
					ans += min(N + dis + list[i].second, N + M - dis + M - list[i].second);
				}
			}
			else {
				if (list[i].first == 1) {
					ans += (dis + M - list[i].second);
				}
				else if (list[i].first == 2) {
					ans += (M - dis + N - list[i].second);
				}
				else {
					ans += min(N + dis + list[i].second, N + M - dis + M - list[i].second);
				}
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> list[i].first >> list[i].second;
	}
	cin >> direct >> dis;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}