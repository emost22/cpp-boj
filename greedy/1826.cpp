#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> q;
pair<int, int> list[10001];
int N, des, now, ans;

void func() {
	int idx = 0;
	while (idx < N) {
		if (now >= list[idx].first) {
			q.push(list[idx].second);
		}
		else {
			if (q.empty()) break;
			now += q.top();
			q.pop();
			ans++;
		}
		idx++;
	}
	while (!q.empty()) {
		if (now >= des) break;
		
		now += q.top();
		q.pop();
		ans++;
	}

	if (now >= des) cout << ans << '\n';
	else cout << "-1\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	cin >> des >> now;
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}