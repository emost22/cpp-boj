#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_N 1001
#define MAX_COST 501
using namespace std;
typedef pair<int, int> pii;

typedef struct Node {
	char type;
	int cost;
	vector<int> next;
}Node;

Node list[MAX_N];
bool visit[MAX_N][MAX_COST];
int N;

bool bfs(int s) {
	queue<pii> q;
	if (list[s].type == 'T' && list[s].cost) return false;
	else {
		q.push({ s,list[s].cost });
		visit[s][list[s].cost] = true;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (x == N) return true;

		for (auto next : list[x].next) {
			if (list[next].type == 'T') {
				if (cost < list[next].cost) continue;
				if (visit[next][cost - list[next].cost]) continue;
				q.push({ next, cost - list[next].cost });
				visit[next][cost - list[next].cost] = true;
			}
			else {
				if (visit[next][max(cost, list[next].cost)]) continue;
				q.push({ next, max(cost, list[next].cost) });
				visit[next][max(cost, list[next].cost)] = true;
			}
		}
	}

	return false;
}

void func() {
	if (bfs(1)) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	cin >> N;
	if (!N) exit(0);

	int x;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].type >> list[i].cost;
		while (1) {
			cin >> x;
			if (!x) break;
			list[i].next.push_back(x);
		}
	}
}

void init() {
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= N; i++) {
		list[i].next.clear();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
		init();
	}

	return 0;
}