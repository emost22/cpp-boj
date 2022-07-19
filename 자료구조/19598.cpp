#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

priority_queue<int, vector<int>, cmp> q;
pii list[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
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