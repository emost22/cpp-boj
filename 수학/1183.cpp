#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	if (N & 1) cout << "1\n";
	else cout << (list[N >> 1] - list[(N >> 1) - 1] + 1) << '\n';
}

void input() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		list[i] = y - x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}