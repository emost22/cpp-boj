#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
typedef pair<int, int> pi;

pi list[MAX];
int N, M, K;

bool cmp(pi a, pi b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

void func() {
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (cnt == K) break;
		if (list[i].second <= M) {
			ans += 140;
			cnt++;
		}
		else if (list[i].first <= M) {
			ans += 100;
			cnt++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	sort(list, list + N, cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}