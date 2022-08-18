#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	sort(list, list + N);

	int pre = 1e9 + 1;
	int cnt = -1;
	for (int i = 0; i < N; i++) {
		if (pre != list[i].first) cnt++;
		pre = list[i].first;
		list[i].first = cnt;
	}
	sort(list, list + N, [](pii a, pii b) {
		return a.second < b.second;
	});

	for (int i = 0; i < N; i++) {
		cout << list[i].first << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
		list[i].second = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}