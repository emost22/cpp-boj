#include <iostream>
#define MAX 1000001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, M, K;

void func() {
	int sum = 0;
	for (int i = 0; i < M; i++) {
		sum += list[i].second;
		if (sum > K) {
			cout << i + 1 << " 1\n";
			return;
		}
	}
	cout << "-1\n";
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}