#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;

int list[2][MAX];
int N;

void func() {
	sort(list[0], list[0] + N);
	sort(list[1], list[1] + N);
	cout << max(list[0][N - 1] - list[0][0], list[1][N - 1] - list[1][0]) << '\n';
}

void input() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		list[0][i] = x + y;
		list[1][i] = x - y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}