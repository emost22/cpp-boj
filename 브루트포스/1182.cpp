#include <iostream>
using namespace std;

int list[20], ans, N, S;
bool visit[20];

void find(int s, int sum, int num, int cnt) {
	if (num == cnt) {
		if (sum == S) {
			ans++;
			return;
		}
	}

	for (int i = s; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			find(i + 1, sum + list[i], num, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		if (list[i] == S) ans++;
	}

	for (int i = 2; i <= N; i++) {
		find(0, 0, i, 0);
		for (int j = 0; j < N; j++) visit[j] = false;
	}

	cout << ans << '\n';

	return 0;
}