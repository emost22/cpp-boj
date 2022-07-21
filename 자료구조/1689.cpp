#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1000001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	priority_queue<int, vector<int>, greater<int>> q;
	q.push(list[0].second);
	int ans = 1;
	for (int i = 1; i < N; i++) {
		while (!q.empty() && q.top() <= list[i].first) q.pop();

		q.push(list[i].second);
		ans = max(ans, (int)q.size());
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