#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

int getDistance(int x, int y) {
	return abs(list[x].first - list[y].first) + abs(list[x].second - list[y].second);
}

void func() {
	int sum = 0;
	for (int i = 1; i < N; i++) {
		sum += getDistance(i - 1, i);
	}

	int ret = 1e9;
	for (int i = 1; i < N - 1; i++) {
		ret = min(ret, sum - getDistance(i - 1, i) - getDistance(i, i + 1) + getDistance(i - 1, i + 1));
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