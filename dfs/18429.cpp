#include <iostream>
#define MAX 8
using namespace std;

int list[MAX];
bool visit[MAX];
int N, K, ret;

void dfs(int x, int now, int cnt) {
	visit[x] = true;
	if (now < 500) return;
	if (cnt == N) {
		ret++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		dfs(i, now + list[i] - K, cnt + 1);
		visit[i] = false;
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		dfs(i, 500 + list[i] - K, 1);
		visit[i] = false;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}