#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M;

void func() {
	int ans = 0;
	int pos = 0;
	for (int i = 0; i < N; i++) {
		if (pos >= list[i].second) continue;
		if (pos < list[i].first) pos = list[i].first;

		int cnt = (list[i].second - pos) / M;
		if ((list[i].second - pos) % M) cnt++;
		ans += cnt;
		pos += (cnt * M);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}