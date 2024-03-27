#include <iostream>
#include <queue>
using namespace std;

deque<int> q;
int N, K, M;

void init() {
	for (int i = 1; i <= N; i++) {
		q.push_back(i);
	}
}

void func() {
	init();

	bool d = false;
	for (int t = 1; !q.empty(); t++) {
		int k = K;
		while (k--) {
			if (!d) {
				int x = q.front();
				q.pop_front();
				if (k) q.push_back(x);
				else cout << x << '\n';
			}
			else {
				int x = q.back();
				q.pop_back();
				if (k) q.push_front(x);
				else cout << x << '\n';
			}
		}

		if (!(t % M)) d = !d;
	}
}

void input() {
	cin >> N >> K >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}