#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M, H;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += max(list[i].first * M, list[i].second * H);
	}
	cout << ret << '\n';
}

void input() {
	cin >> M >> H >> N;
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