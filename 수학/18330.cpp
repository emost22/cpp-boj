#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

void func() {
	int x = min(60 + M, N);
	int y = max(N - 60 - M, 0);

	cout << x * 1500 + y * 3000 << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}