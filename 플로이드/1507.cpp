#include <iostream>
using namespace std;

int graph[20][20], N, sum;
bool visit[20][20], chk;

void floyd() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (i == j || i == k || j == k) continue;

				if (graph[j][k] > graph[j][i] + graph[i][k]) {
					chk = true;
				}
				else if (graph[j][k] == graph[j][i] + graph[i][k]) {
					visit[j][k] = -1;
				}
			}
		}
	}

	if (chk) {
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!visit[i][j]) sum += graph[i][j];
		}
	}

	cout << sum << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	floyd();

	return 0;
}