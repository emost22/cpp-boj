#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int N;

void func() {
	vector<int> tmp;
	tmp.push_back(N);

	int ret = 0;
	int len = 2;
	for (int i = (N >> 1); i <= N; i++) {
		tmp.push_back(i);
		while (1) {
			int next = tmp[len - 2] - tmp[len - 1];
			if (next < 0) break;
			tmp.push_back(next);
			len++;
		}

		if (ret < len) {
			ret = len;
			v = tmp;
		}
		len = 2;
		tmp.clear();
		tmp.push_back(N);
	}

	cout << ret << '\n';
	for (auto x : v) {
		cout << x << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}