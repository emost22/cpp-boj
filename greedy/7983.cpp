#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

bool cmp(pii a, pii b) {
	return a.second > b.second;
}

void func() {
	sort(list, list + N, cmp);
	int ret = 1e9;
	for (int i = 0; i < N; i++) {
		ret = min(ret, list[i].second);
		ret -= list[i].first;
		if (ret < 0) {
			ret = 0;
			break;
		}
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