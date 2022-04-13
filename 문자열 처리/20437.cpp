#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 26
using namespace std;

string str;
vector<int> v[MAX];
int cnt[MAX];
int N, K;

void func() {
	for (int i = 0; i < N; i++) {
		v[str[i] - 'a'].push_back(i);
	}

	int minAns = 1e9;
	int maxAns = -1;
	for (int i = 0; i < MAX; i++) {
		int vsize = v[i].size();
		if (vsize < K) continue;

		for (int j = 0; j < vsize - K + 1; j++) {
			int l = v[i][j];
			int r = v[i][j + K - 1];

			minAns = min(minAns, r - l + 1);
			maxAns = max(maxAns, r - l + 1);
		}
	}

	if (maxAns == -1) cout << maxAns << '\n';
	else cout << minAns << ' ' << maxAns << '\n';
}

void input() {
	cin >> str >> K;
	N = str.size();
}

void init() {
	memset(cnt, false, sizeof(cnt));
	for (int i = 0; i < MAX; i++) {
		v[i].clear();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}