#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX];
int N;

void func() {
	int mx = max(list[0], list[N - 1]);
	int mn = min(list[0], list[N - 1]);
	if (mx - (N - 3) >= mn) {
		cout << mx - (N - 2) << '\n';
	}
	else {
		cout << mn - ((N - 3 - (mx - mn)) >> 1) - 1 << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}