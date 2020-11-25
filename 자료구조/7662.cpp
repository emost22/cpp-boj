#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int K;
char ch;
bool visit[1000001];

void input() {
	priority_queue<pair<int, int> > maxq;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
	int x;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> ch >> x;

		while (!maxq.empty() && !visit[maxq.top().second]) maxq.pop();
		while (!minq.empty() && !visit[minq.top().second]) minq.pop();

		if (ch == 'I') {
			visit[i] = true;
			maxq.push({ x,i });
			minq.push({ x,i });
		}
		else {
			if (maxq.empty() || minq.empty()) continue;
			if (x == 1) {
				visit[maxq.top().second] = false;
				maxq.pop();
			}
			else {
				visit[minq.top().second] = false;
				minq.pop();
			}
		}
	}
	while (!maxq.empty() && !visit[maxq.top().second]) maxq.pop();
	while (!minq.empty() && !visit[minq.top().second]) minq.pop();

	if (maxq.empty() && minq.empty()) {
		cout << "EMPTY\n";
	}
	else {
		cout << maxq.top().first << ' ' << minq.top().first << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}