#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, X;

void func() {
	int ret = -1;
	for (int i = 0; i < N; i++) {
		if (list[i].first + list[i].second > X) continue;
		ret = max(ret, list[i].first);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> X;
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