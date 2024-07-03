#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

void func() {
	sort(list, list + N, cmp);

	int t = 1e9;
	for (int i = 0; i < N; i++) {
		t = min(t, list[i].second);
		t -= list[i].first;

		if (t < 0) {
			cout << "-1\n";
			return;
		}
	}

	cout << t << '\n';
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