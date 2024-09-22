#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	int l = 0;
	int r = 1e9;
	for (int i = 0; i < N; i++) {
		l = max(l, list[i].first);
		r = min(r, list[i].second);
	}
	if (l - r < 0) l = r;

	cout << l - r << '\n';
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