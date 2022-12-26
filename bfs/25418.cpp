#include <iostream>
#include <queue>
#define MAX 1000001
using namespace std;

queue<int> q;
bool visit[MAX];
int A, K;

void func() {
	q.push(A);
	visit[A] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == K) {
				cout << t << '\n';
				return;
			}

			if (x + 1 < MAX) {
				if (!visit[x + 1]) {
					q.push(x + 1);
					visit[x + 1] = true;
				}
			}

			if (x * 2 < MAX) {
				if (!visit[x * 2]) {
					q.push(x * 2);
					visit[x * 2] = true;
				}
			}
		}
	}
}

void input() {
	cin >> A >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}