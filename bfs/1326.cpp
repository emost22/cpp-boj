#include <iostream>
#include <queue>
#define MAX 10001
using namespace std;

int list[MAX];
bool visit[MAX];
int N, S, E;

int bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == E) return t;

			for (int i = 1; ; i++) {
				int next = x + list[x] * i;

				if (next > N) break;
				if (visit[next]) continue;

				q.push(next);
				visit[next];
			}

			for (int i = 1; ; i++) {
				int next = x - list[x] * i;

				if (next < 1) break;
				if (visit[next]) continue;

				q.push(next);
				visit[next];
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	cin >> S >> E;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}