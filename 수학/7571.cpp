#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int x[MAX], y[MAX];
int N, M;

void func() {
	sort(x, x + M);
	sort(y, y + M);

	int mx = x[M >> 1];
	int my = y[M >> 1];
	int ret = 0;
	for (int i = 0; i < M; i++) {
		ret += (abs(x[i] - mx) + abs(y[i] - my));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x[i] >> y[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}