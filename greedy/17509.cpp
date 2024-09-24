#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];

void func() {
	sort(list, list + MAX);

	int ret = 0;
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		sum += list[i].first;
		ret += (sum + list[i].second * 20);
	}
	cout << ret << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
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