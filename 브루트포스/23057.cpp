#include <iostream>
#include <set>
using namespace std;

set<int> s;
int list[20];
int N, M;

void solve(int idx, int sum) {
	s.insert(sum);
	if (idx == N) {
		return;
	}
	solve(idx + 1, sum);
	solve(idx + 1, sum + list[idx]);
}

void func() {
	solve(0, 0);
	cout << M - s.size() + 1 << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		M += list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}