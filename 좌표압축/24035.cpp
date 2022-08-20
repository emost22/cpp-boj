#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int list[MAX];
int N;

void func(int tc) {
	sort(list, list + N);

	int pre = 1e9;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (pre != list[i]) cnt++;
		pre = list[i];
		ans += cnt;
	}

	cout << "Case #" << tc << ": " << ans << '\n';
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

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}