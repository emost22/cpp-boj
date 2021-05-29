#include <iostream>
#include <algorithm>
#define INF 1000000001
using namespace std;

pair<int, int> list[1000000];
int ans[1000000], N;

void print() {
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void func() {
	int x = -1;
	int pre = INF;
	for (int i = 0; i < N; i++) {
		if (list[i].first == pre) {
			ans[list[i].second] = x;
		}
		else {
			pre = list[i].first;
			ans[list[i].second] = ++x;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
		list[i].second = i;
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	print();

	return 0;
}