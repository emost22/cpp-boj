#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M;

void func() {
	sort(list + 1, list + 1 + N, [](pii a, pii b) {
		return a.first > b.first;
	});

	for (int i = 0; i <= N && M; i++) {
		if (list[0].first < list[i].first) continue;
		M--;
		cout << list[i].second << ' ';
	}
	cout << '\n';
}

void input() {
	int v, p, s;
	cin >> N >> M >> v >> p >> s;
	list[0].first = v + p + s;
	for (int i = 1; i <= N; i++) {
		cin >> v >> p >> s;
		list[i].first = v + p + s;
		list[i].second = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}