#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 2147483647
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M;

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

void func() {
	sort(list, list + N, cmp);

	int before = 0;
	int price = 0;
	int weight = 0;
	int ret = INF;
	for (int i = 0; i < N; i++) {
		weight += list[i].first;

		if (before < list[i].second) {
			price = before = list[i].second;
		}
		else {
			price += list[i].second;
		}

		if (weight >= M) {
			ret = min(ret, price);
		}
	}
	if (weight < M) ret = -1;

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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