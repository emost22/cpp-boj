#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M;

void func() {
	sort(list, list + M, [](pii a, pii b) {
		return a.first > b.first;
	});

	int ret = 0;
	for (int i = 0; i < M - 1; i++) {
		if (list[i].first >= N) continue;
		ret += (N - list[i].first);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
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