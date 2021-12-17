#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 300001
using namespace std;
typedef long long ll;

vector<int> graph[MAX];
bool visit[MAX];
ll conn[MAX];
int N;

void func() {
	ll D = 0;
	ll G = 0;
	for (int i = 1; i <= N; i++) {
		if (conn[i] >= 3) {
			G += ((conn[i] * (conn[i] - 1) * (conn[i] - 2)) / 6LL);
		}
	}

	for (int i = 1; i <= N; i++) {
		int s = graph[i].size();

		for (int j = 0; j < s; j++) {
			int next = graph[i][j];
			int e = graph[next].size();

			if (visit[next]) continue;

			D += ((s - 1) * (e - 1));
		}

		visit[i] = true;
	}

	if (G * 3 < D) {
		cout << "D\n";
	}
	else if (G * 3 > D) {
		cout << "G\n";
	}
	else {
		cout << "DUDUDUNGA\n";
	}
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
		conn[u]++;
		conn[v]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}