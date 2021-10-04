#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> list, weight;
int N, M;

void func() {
	if (list[M - 1] > weight[N - 1]) {
		cout << "-1\n";
		return;
	}

	for (int t = 1; ; t++) {
		for (int i = 0; i < weight.size(); i++) {
			int idx = upper_bound(list.begin(), list.end(), weight[i]) - list.begin();
			if (idx != 0) list.erase(list.begin() + idx - 1);
		}

		if (list.empty()) {
			cout << t << '\n';
			return;
		}
	}
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		weight.push_back(x);
	}
	sort(weight.begin(), weight.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		list.push_back(x);
	}
	sort(list.begin(), list.end());
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}