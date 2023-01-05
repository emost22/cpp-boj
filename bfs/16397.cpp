#include <iostream>
#include <queue>
#include <string>
#define MAX 100000
using namespace std;

bool visit[MAX];
int s, T, e;

void insertNext(queue<int> &q, int x) {
	if (x < MAX && !visit[x]) {
		q.push(x);
		visit[x] = true;
	}
}

string bfs() {
	queue<int> q;
	q.push(s);
	visit[s] = true;
	for (int t = 0; !q.empty() && t <= T; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x == e) {
				return to_string(t);
			}

			insertNext(q, x + 1);
			if (x * 2 < MAX) {
				string nxStr = to_string(x * 2);
				if (nxStr[0] > '0') nxStr[0] -= 1;
				insertNext(q, stoi(nxStr));
			}
 		}
	}

	return "ANG";
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> s >> T >> e;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}