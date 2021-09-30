#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef pair<int, int> pi;

pi list[MAX];
int N;

void func() {
	int bestRank = list[0].second;
	int ans = 1;
	for (int i = 1; i < N; i++) {
		if (bestRank > list[i].second) {
			ans++;
			bestRank = list[i].second;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
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