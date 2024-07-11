#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, X;

bool cmp(pii a, pii b) {
	return a.first - a.second > b.first - b.second;
}

void func() {
	sort(list, list + N, cmp);

	int ret = 0;
	int cost = N * 1000;
	for (int i = 0; i < N; i++) {
		if (cost + 4000 <= X && list[i].first > list[i].second) {
			cost += 4000;
			ret += list[i].first;
		}
		else ret += list[i].second;
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