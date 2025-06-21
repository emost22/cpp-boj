#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 100001
#define MAX_Y 10011
using namespace std;
typedef pair<int, int> pii;

pii list[MAX_N];
int cnt[MAX_Y][MAX_Y];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int sx = list[i].first;
		int sy = list[i].second;
		for (int j = sx; j <= sx + 10; j++) {
			for (int k = sy; k <= sy + 10; k++) {
				cnt[j][k]++;
				ret = max(ret, cnt[j][k]);
			}
		}
	}

	cout << ret << '\n';
	memset(cnt, 0, sizeof(cnt));
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
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
	}

	return 0;
}