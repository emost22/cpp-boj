#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	sort(list, list + N);

	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret = max(ret, list[i].second - i);
	}

	cout << ret + 1 << '\n';
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