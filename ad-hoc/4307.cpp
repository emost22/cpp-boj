#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, len;

void func() {
	int minAns = 0;
	int maxAns = 0;
	for (int i = 0; i < N; i++) {
		minAns = max(minAns, min(list[i], len - list[i]));
		maxAns = max(maxAns, max(list[i], len - list[i]));
	}

	cout << minAns << ' ' << maxAns << '\n';
}

void input() {
	cin >> len >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
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