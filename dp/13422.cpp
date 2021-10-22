#include <iostream>
#define MAX 200001
using namespace std;

int list[MAX];
int N, M, K;

void func() {
	if (N == M) {
		if (list[N] < K) cout << "1\n";
		else cout << "0\n";
		return;
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = list[i + M - 1] - list[i - 1];
		if (sum >= K) continue;

		ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		list[i + N] = list[i];
	}

	for (int i = 1; i <= N * 2; i++) {
		list[i] += list[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}