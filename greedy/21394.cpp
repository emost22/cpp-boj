#include <iostream>
#include <queue>
#define MAX 10
using namespace std;

int cnt[MAX], N;

void func() {
	cnt[9] += cnt[6];
	cnt[6] = 0;

	deque<int> q;
	bool flag = N & 1;
	for (int i = 1; i < MAX; i++) {
		while (cnt[i]--) {
			if (flag) q.push_front(i);
			else q.push_back(i);
			flag = !flag;
		}
	}

	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop_front();
	}
	cout << '\n';
	N = 0;
}

void input() {
	for (int i = 1; i < MAX; i++) {
		cin >> cnt[i];
		N += cnt[i];
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
	}

	return 0;
}