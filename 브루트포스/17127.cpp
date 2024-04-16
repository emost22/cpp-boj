#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
#define MAX_CNT 4
using namespace std;

vector<int> v;
int list[MAX];
int N, ret;

void solve(int idx, int cnt) {
	if (MAX_CNT - cnt > N - idx) return;
	if (cnt == MAX_CNT) {
		int s = 0;
		int sum = 0;
		for (auto e : v) {
			int mul = 1;
			for (int i = s; i <= e; i++) {
				mul *= list[i];
			}
			sum += mul;
			s = e + 1;
		}
		ret = max(ret, sum);
		return;
	}

	for (int i = idx; i < N; i++) {
		v.push_back(i);
		solve(i + 1, cnt + 1);
		v.pop_back();
	}
}

void func() {
	solve(0, 0);
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}