#include <iostream>
#include <algorithm>
using namespace std;

const int t = 4;
int N, w, h;

void func() {
	cout << max(w, N - w) * max(h, N - h) * t << '\n';
}

void input() {
	cin >> N >> w >> h;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}