#include <iostream>
using namespace std;

int list[13];
bool visit[13];

void dfs(int s, int N, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < N; i++) {
			if (visit[i]) {
				cout << list[i] << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = s; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i + 1, N, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	while (1) {
		cin >> N;
		if (!N) break;

		for (int i = 0; i < N; i++) {
			cin >> list[i];
		}

		dfs(0, N, 0);
		cout << '\n';
	}

	return 0;
}