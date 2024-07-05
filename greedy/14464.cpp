#include <iostream>
#include <algorithm>
#define MAX 20001
using namespace std;
typedef pair<int, int> pii;

int list[MAX];
pii cow[MAX];
int N, M;

void func() {
	sort(list, list + N);
	sort(cow, cow + M, [](pii a, pii b) {
		return a.second < b.second;
	});

	int ret = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (list[j] == -1) continue;
			if (cow[i].first > list[j] || list[j] > cow[i].second) continue;

			ret++;
			list[j] = -1;
			break;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> cow[i].first >> cow[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}