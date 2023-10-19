#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

queue<int> q;
pii list[MAX];
int N, M;

void func() {
	int x;
	cin >> M;
	while (M--) {
		cin >> x;
		q.push(x);
		cout << q.front() << ' ';
		q.pop();
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first;
	}

	for (int i = 0; i < N; i++) {
		cin >> list[i].second;
	}

	for (int i = N - 1; i >= 0; i--) {
		if (list[i].first) continue;
		q.push(list[i].second);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}