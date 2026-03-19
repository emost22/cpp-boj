#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M, K;

int getDistance(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void func() {
	pii e = { 1,M + 1 };
	int ret = 0;
	int mn = 1e9;
	for (int i = 0; i < K; i++) {
		int dis = getDistance(list[i], e);

		if (mn > dis) {
			mn = dis;
			ret = i + 1;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
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