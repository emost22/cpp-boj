#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

vector<int> a, b;
int N, M;

void func() {
	vector<int> v;
	while (1) {
		int aIdx = 0;
		int bIdx = 0;
		while (1) {
			if (a.empty() || b.empty()) break;

			aIdx = max_element(a.begin(), a.end()) - a.begin();
			bIdx = max_element(b.begin(), b.end()) - b.begin();
			if (a[aIdx] == b[bIdx]) break;
			if (a[aIdx] > b[bIdx]) a.erase(a.begin() + aIdx);
			else b.erase(b.begin() + bIdx);
		}
		if (a.empty() || b.empty()) break;
		v.push_back(a[aIdx]);

		for (int i = 0; i <= aIdx; i++) a.erase(a.begin());
		for (int i = 0; i <= bIdx; i++) b.erase(b.begin());
	}

	cout << v.size() << '\n';
	for (auto x : v) {
		cout << x << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		a.push_back(x);
	}

	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> x;
		b.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}