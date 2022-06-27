#include <iostream>
#include <algorithm>
#define MAX 1002
using namespace std;

bool flag[MAX];
int N, M;

void func() {
	int ans = 2e9;
	for (int i = 1; i < MAX; i++) {
		if (flag[i]) continue;
		for (int j = i; j < MAX; j++) {
			if (flag[j]) continue;
			for (int k = j; k < MAX; k++) {
				if (flag[k]) continue;
				ans = min(ans, abs(N - i * j * k));
			}
		}

		if (!ans) break;
	}

	cout << ans << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		flag[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}