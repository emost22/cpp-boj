#include <iostream>
#include <queue>
#define MAX 100
using namespace std;
typedef pair<int, int> pi;

priority_queue<int> q[MAX];
pi list[MAX];
int N, M;

void func() {
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int listSize = list[i].first;
		int limitSize = list[i].second;
		while (1) {
			if (listSize < limitSize) {
				pq.push(-1);
				break;
			}
			else if (listSize == limitSize) {
				pq.push(q[i].top());
				break;
			}
			q[i].pop();
			listSize--;
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		int x = -pq.top();
		pq.pop();
		M -= x;
		if (M < 0) break;

		ans++;
	}

	cout << ans << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		for (int j = 0; j < list[i].first; j++) {
			cin >> x;
			q[i].push(-x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}