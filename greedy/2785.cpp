#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int N;

void func() {
	sort(v.begin(), v.end());

	int ret = 0;
	while (v.size() > 1) {
		ret++;
		v[N - 2] += v[N - 1];
		v.pop_back();
		N--;
		v[0]--;

		if (!v[0]) {
			v.erase(v.begin());
			N--;
		}
	}

	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}