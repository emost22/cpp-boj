#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, cnt;
int list[10000];

struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

void func() {
	priority_queue<int> lq;
	priority_queue<int, vector<int>, cmp> rq;
	int lsize = 0;
	int rsize = 0;

	for (int i = 0; i < N; i++) {
		if (lq.empty() && rq.empty()) {
			rq.push(list[i]);
			rsize++;
		}
		else if (rq.top() > list[i]) {
			lq.push(list[i]);
			lsize++;

			if (lsize > rsize) {
				lsize--;
				rsize++;
				rq.push(lq.top());
				lq.pop();
			}
		}
		else {
			rq.push(list[i]);
			rsize++;

			if (rsize > lsize + 1) {
				rsize--;
				lsize++;
				lq.push(rq.top());
				rq.pop();
			}
		}

		if (i % 2 == 0) {
			if (cnt == 10) {
				cout << '\n';
				cnt = 0;
			}
			cout << rq.top() << ' ';
			cnt++;
		}
	}
	cout << '\n';
}

void input() {
	cin >> N;
	cout << (N + 1) / 2 << '\n';
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		cnt = 0;
	}

	return 0;
}