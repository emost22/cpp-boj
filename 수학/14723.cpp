#include <iostream>
using namespace std;

int N;

void func() {
	int cnt = 1;
	int diff = 0;
	for (; cnt + diff <= N; diff++) {
		cnt += diff;
	}

	int x = diff;
	int y = 1;

	x -= (N - cnt);
	y += (N - cnt);

	cout << x << ' ' << y << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}