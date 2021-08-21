#include <iostream>
using namespace std;

bool visit[10001];
int M, N, ans, sum;

void init() {
	for (int i = 0; i <= 100; i++) {
		visit[i * i] = true;
	}
}

void input() {
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (visit[i]) {
			if (!ans) ans = i;
			sum += i;
		}
	}

	if (!ans) cout << "-1\n";
	else cout << sum << '\n' << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}