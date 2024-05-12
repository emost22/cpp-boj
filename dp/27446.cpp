#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

vector<int> v;
int list[MAX];
bool chk[MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		if (chk[i]) continue;
		v.push_back(i);
	}
}

void func() {
	init();
	int ret = v.empty() ? 0 : 7;
	for (int i = 1; i < v.size(); i++) {
		ret += min(7, (v[i] - v[i - 1]) << 1);
	}

	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	while (M--) {
		cin >> x;
		chk[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}