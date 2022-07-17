#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	int l = list[0].first;
	int r = list[0].second;
	int ans = r - l;
	for (int i = 1; i < N; i++) {
		if (l <= list[i].first && list[i].second <= r) continue;

		if (list[i].first < r) {
			ans += (list[i].second - r);
			r = list[i].second;
		}
		else {
			ans += (list[i].second - list[i].first);
			l = list[i].first;
			r = list[i].second;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}