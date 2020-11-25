#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
deque<pair<int, int> > q;
vector<int> ans;

void func() {
	while (1) {
		ans.push_back(q.front().first);
		int next = q.front().second;
		q.pop_front();
		if (q.empty()) break;

		if (next > 0) {
			while (next--) {
				q.push_back(q.front());
				q.pop_front();
			}
		}
		else {
			while (next++) {
				q.push_front(q.back());
				q.pop_back();
			}
		}
	}
}

void print() {
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		if (x > 0) x--;
		q.push_back({ i,x });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	print();

	return 0;
}