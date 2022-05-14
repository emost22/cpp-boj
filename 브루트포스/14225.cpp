#include <iostream>
#define CNT 21
#define MAX 2000001
using namespace std;

int list[CNT];
bool visit[MAX];
int N;

void dfs(int idx, int sum) {
	if (sum > 0) visit[sum] = true;
	if (idx == N) return;

	for (int i = idx; i < N; i++) {
		dfs(i + 1, sum + list[i]);
	}
}

void func() {
	dfs(0, 0);

	for (int i = 1; i < MAX; i++) {
		if (visit[i]) continue;
		
		cout << i << '\n';
		return;
	}
}

void input() {
	cin >> N;
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