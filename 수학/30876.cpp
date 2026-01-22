#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N;

void func() {
	sort(list, list + N, [](pii a, pii b) {
		return a.second < b.second;
	});

	cout << list[0].first << ' ' << list[0].second << '\n';
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