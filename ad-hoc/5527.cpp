#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> v;
int list[MAX];
int N;

void init() {
	int pre = list[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (pre == list[i]) {
			v.push_back(cnt);
			cnt = 1;
		}
		else {
			cnt++;
		}
		pre = list[i];
	}
	v.push_back(cnt);
}

void func() {
	init();

	int ret = 0;
	if (v.size() < 3) {
		for (auto x : v) {
			ret += x;
		}
	}
	else {
		for (int i = 1; i < v.size() - 1; i++) {
			ret = max(ret, v[i - 1] + v[i] + v[i + 1]);
		}
	}
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