#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 0;
	int mxPrice = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += max(0, list[i].first - list[j].second);
		}

		if (mxPrice < sum) {
			mxPrice = sum;
			ret = list[i].first;
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