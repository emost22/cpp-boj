#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, ans;
int list[1001], lis[1001];
int N, length, lisidx;

void print() {
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void solve() {
	length = v.size();
	for (int i = N; i >= 1; i--) {
		if (lis[i] == length) {
			ans.push_back(list[i]);
			length--;
		}

		if (!length) return;
	}
}

void func() {
	v.push_back(list[1]);
	lisidx++;
	lis[1] = 1;
	for (int i = 2; i <= N; i++) {
		if (v[v.size() - 1] < list[i]) {
			v.push_back(list[i]);
			lisidx++;
			lis[i] = lisidx;
		}
		else {
			int tmp = lower_bound(v.begin(), v.end(), list[i]) - v.begin();

			v[tmp] = list[i];
			lis[i] = tmp + 1;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	solve();
	print();

	return 0;
}