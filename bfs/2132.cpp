#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;
typedef pair<int, int> pii;

vector<int> v[MAX];
int list[MAX];
int w[MAX];
int weight, idx;
int N;

bool isHigher(int we, int i, int x) {
	if (we == w[x]) {
		return i > x;
	}
	return we < w[x];
}

void bfs(int x) {
	memset(w, -1, sizeof(w));

	queue<int> q;
	q.push(x);
	w[x] = list[x];
	weight = list[x];
	idx = x;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (isHigher(weight, idx, now)) {
			idx = now;
			weight = w[now];
		}

		for (auto next : v[now]) {
			if (w[next] != -1) continue;
			w[next] = w[now] + list[next];
			q.push(next);
		}
	}
}

void func() {
	bfs(1);
	int tmp = idx;
	bfs(idx);
	cout << weight << ' ' << min(tmp, idx) << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	int x, y;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}