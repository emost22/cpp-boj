#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

bool police[MAX], visit[MAX];
int N, S, D, F, B, K;

int bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == D) return t;

			if (x + F <= N && !visit[x + F] && !police[x + F]) {
				q.push(x + F);
				visit[x + F] = true;
			}

			if (x - B > 0 && !visit[x - B] && !police[x - B]) {
				q.push(x - B);
				visit[x - B] = true;
			}
		}
	}

	return -1;
}

void func() {
	int ret = bfs();
	if (ret == -1) cout << "BUG FOUND\n";
	else cout << ret << '\n';
}

void input() {
	int x;
	cin >> N >> S >> D >> F >> B >> K;
	for (int i = 0; i < K; i++) {
		cin >> x;
		police[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}