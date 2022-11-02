#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	int ans = 1e9;
	for (int i = 0; i < N; i++) {
		if (list[i].first <= list[i].second) {
			ans = min(ans, list[i].second);
		}
	}

	if (ans == 1e9) ans = -1;
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}