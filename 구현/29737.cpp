#include <iostream>
#include <algorithm>
#include <string>
#define MAX 101
using namespace std;

typedef struct Node {
	string id;
	int cnt;
	int streak;
	int s;
	int failed;
	int rank;
}Node;

Node list[MAX];
string str[7];
int N, W;

bool cmp(Node a, Node b) {
	if (a.cnt == b.cnt) {
		if (a.streak == b.streak) {
			if (a.s == b.s) {
				if (a.failed == b.failed) {
					return a.id < b.id;
				}
				return a.failed < b.failed;
			}
			return a.s < b.s;
		}
		return a.streak < b.streak;
	}
	return a.cnt > b.cnt;
}

bool isSameStreak(Node a, Node b) {
	return a.cnt == b.cnt && a.streak == b.streak && a.s == b.s && a.failed == b.failed;
}

void func() {
	sort(list, list + N, cmp);

	list[0].rank = 1;
	for (int i = 1; i < N; i++) {
		if (isSameStreak(list[i - 1], list[i])) list[i].rank = list[i - 1].rank;
		else list[i].rank = list[i - 1].rank + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << list[i].rank << ". " << list[i].id << '\n';
	}
}

bool isHigherRank(Node x, int cnt, int streak) {
	if (!cnt) return false;

	if (x.cnt == cnt) {
		return streak < x.streak;
	}
	return cnt > x.cnt;
}

void countStreak(int idx) {
	int cnt = 0;
	int streak = 0;
	int s = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < 7; j++) {
			if (str[j][i] == 'F') {
				if (cnt) {
					streak++;
				}
				continue;
			}

			if (str[j][i] == 'X') {
				cnt = 0;
				streak = 0;
				list[idx].failed++;
			}
			else {
				if (!cnt) s = i * 7 + j + 1;
				cnt++;
				if (isHigherRank(list[idx], cnt, streak)) {
					list[idx].cnt = cnt;
					list[idx].streak = streak;
					list[idx].s = s;
				}
			}
		}
	}
}

void input() {
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		cin >> list[i].id;

		for (int j = 0; j < 7; j++) {
			cin >> str[j];
		}

		countStreak(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}