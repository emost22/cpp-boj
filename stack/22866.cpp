#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 100001
using namespace std;
typedef pair<int, int> pi;

int list[MAX];
pi ans[MAX];
int N;

void func() {
	stack<pi> l, r;
	for (int i = 1; i <= N; i++) {
		while (!l.empty() && l.top().first <= list[i]) l.pop();

		int lsize = l.size();
		ans[i].first = lsize;
		if (lsize > 0) {
			ans[i].second = l.top().second;
		}
		else {
			ans[i].second = 1e9;
		}
		l.push({ list[i], i });
	}

	for (int i = N; i >= 1; i--) {
		while (!r.empty() && r.top().first <= list[i]) r.pop();

		int rsize = r.size();
		ans[i].first += rsize;
		if (rsize > 0) {
			if (abs(ans[i].second - i) > abs(i - r.top().second)) {
				ans[i].second = r.top().second;
			}
			else if (abs(ans[i].second - i) == abs(i - r.top().second)) {
				ans[i].second = min(ans[i].second, r.top().second);
			}
		}
		r.push({ list[i], i });
	}

	for (int i = 1; i <= N; i++) {
		if (ans[i].first) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
		}
		else {
			cout << "0\n";
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}