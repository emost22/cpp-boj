#include <iostream>
#include <algorithm>
#define MAX 30001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, K, S;

void func() {
	sort(list, list + N);

	int idx = 0;
	int ret = 0;
	while (idx < N && list[idx].first < S) {
		ret += ((S - list[idx].first) << 1);
		int cnt = 0;
		while (idx < N && list[idx].first < S && cnt < K) {
			int tmp = min(K - cnt, list[idx].second);
			cnt += tmp;
			list[idx].second -= tmp;
			if (!list[idx].second) idx++;
		}
	}

	idx = N - 1;
	while (idx >= 0 && list[idx].first > S) {
		ret += ((list[idx].first - S) << 1);
		int cnt = 0;
		while (idx >= 0 && list[idx].first > S && cnt < K) {
			int tmp = min(K - cnt, list[idx].second);
			cnt += tmp;
			list[idx].second -= tmp;
			if (!list[idx].second) idx--;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> K >> S;
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