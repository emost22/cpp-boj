#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M, K;

void func() {
	sort(list, list + N, [](pii a, pii b) {
		return a.second < b.second;
	});

	int sum = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	for (int i = 0; i < N; i++) {
		q.push(list[i].first);
		sum += list[i].first;

		if (q.size() > K) {
			sum -= q.top();
			q.pop();
		}

		if (q.size() == K && sum >= M) {
			cout << list[i].second << '\n';
			return;
		}
	}

	cout << "-1\n";
}

void input() {
	cin >> K >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}