#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	sort(list, list + N, [](pii a, pii b) {
		return a.second < b.second;
	});

	int t = list[N - 1].second;
	for (int i = N - 1; i >= 0; i--) {
		if (t > list[i].second) {
			t = list[i].second;
		}

		if (t - list[i].first < 0) {
			cout << "-1\n";
			return;
		}

		t -= list[i].first;
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