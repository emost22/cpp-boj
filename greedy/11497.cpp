#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	ans = max(list[1] - list[0], list[N - 1] - list[N - 2]);
	for (int i = 0; i < N - 2; i++) {
		ans = max(ans, list[i + 2] - list[i]);
	}
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
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