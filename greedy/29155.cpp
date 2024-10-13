#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 6
using namespace std;

vector<int> v[MAX];
int level[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		sort(v[i].begin(), v[i].end());
		ret += v[i][0];
		for (int j = 1; j < level[i]; j++) {
			ret += (abs(v[i][j] - v[i][j - 1]) + v[i][j]);
		}
		if (i != 1) ret += 60;
	}
	cout << ret << '\n';
}

void input() {
	int idx, x;
	cin >> N >> level[1] >> level[2] >> level[3] >> level[4] >> level[5];
	for (int i = 0; i < N; i++) {
		cin >> idx >> x;
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