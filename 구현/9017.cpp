#include <iostream>
#include <cstring>
#define MAX_N 1000
#define MAX_M 201
using namespace std;

int list[MAX_N];
int score[MAX_M], ext[MAX_M], cnt[MAX_M], records[MAX_M];
int N;

int getWinner(int x, int y) {
	if (score[x] < score[y]) return x;
	if (score[x] > score[y]) return y;
	if (ext[x] < ext[y]) return x;
	return y;
}

void func() {
	score[0] = 1e9;
	ext[0] = 1e9;

	int ret = 0;
	int rank = 1;
	for (int i = 0; i < N; i++) {
		int x = list[i];
		if (cnt[x] < 6) continue;

		records[x]++;
		if (records[x] <= 4) {
			score[x] += rank;
		}
		else if (records[x] == 5) {
			ext[x] = rank;
			ret = getWinner(ret, x);
		}

		rank++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		cnt[list[i]]++;
	}
}

void init() {
	memset(score, 0, sizeof(score));
	memset(ext, 0, sizeof(ext));
	memset(cnt, 0, sizeof(cnt));
	memset(records, 0, sizeof(records));
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