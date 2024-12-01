#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 0;
	int now = 0;
	for (auto x : list) {
		if (now < x.first) ret++;
		now = x.first + x.second;
	}
	cout << ret << '\n';
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