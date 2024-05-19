#include <iostream>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M;

void func() {
	int x = 0;
	int ret = 0;
	int pos = list[x].first + list[x].second;
	while (1) {
		if (pos >= M) {
			cout << ret << '\n';
			return;
		}

		int range = pos;
		int idx = 0;
		for (int i = x + 1; i < N; i++) {
			if (pos < list[i].first) break;
			if (range < list[i].first + list[i].second) {
				range = list[i].first + list[i].second;
				idx = i;
			}
		}
		if (range == pos) break;
		ret++;
		pos = range;
		x = idx;
	}

	cout << "-1\n";
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
	}

	for (int i = 0; i < N; i++) {
		cin >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}