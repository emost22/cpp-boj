#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5001
using namespace std;

vector<int> v[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int m = v[i].size();
		if (m < 2) continue;
		sort(v[i].begin(), v[i].end());

		ret += (v[i][1] - v[i][0] + v[i][m - 1] - v[i][m - 2]);
		for (int j = 1; j < m - 1; j++) {
			ret += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
		}
	}
	cout << ret << '\n';
}

void input() {
	int x, idx;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> idx;
		v[idx].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}