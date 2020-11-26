#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> q;
pair<int, int> list[200001];
int N;

void func() {
	q.push(-list[0].second);
	for (int i = 1; i < N; i++) {
		int endtime = -q.top();
		if (endtime > list[i].first) {
			q.push(-list[i].second);
		}
		else {
			q.pop();
			q.push(-list[i].second);
		}
	}

	cout << q.size() << '\n';
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