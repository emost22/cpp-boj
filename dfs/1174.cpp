#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> list;
int N;

void dfs(ll x) {
	list.push_back(x);

	int i = (x % 10) - 1;
	for (; i >= 0; i--) {
		dfs(x * 10 + i);
	}
}

void init() {
	for (int i = 0; i < 10; i++) {
		dfs(i);
	}
}

void func() {
	sort(list.begin(), list.end());
	if (list.size() < N) {
		cout << "-1\n";
		return;
	}

	cout << list[N - 1] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}