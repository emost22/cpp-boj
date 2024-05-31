#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;

int scores[MAX][MAX];
int tries[MAX];
int cnts[MAX];
int N, K, T, M;

int getScore(int team) {
	int ret = 0;
	for (auto score : scores[team]) {
		ret += score;
	}
	return ret;
}

bool isBetter(int team) {
	int x = getScore(T);
	int y = getScore(team);
	if (x == y) {
		if (cnts[T] == cnts[team]) return tries[T] > tries[team];
		return cnts[T] > cnts[team];
	}
	return x < y;
}

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (i == T) continue;
		ret += isBetter(i);
	}
	cout << ret + 1 << '\n';
}

void input() {
	int id, no, s;
	cin >> N >> K >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> id >> no >> s;
		scores[id][no] = max(scores[id][no], s);
		cnts[id]++;
		tries[id] = i;
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		memset(scores[i], 0, sizeof(scores[i]));
	}
	memset(cnts, 0, sizeof(cnts));
	memset(tries, 0, sizeof(tries));
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