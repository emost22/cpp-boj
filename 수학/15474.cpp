#include <iostream>
#include <algorithm>
using namespace std;

int N, A, B, C, D;

int getCnt(int x) {
	return N / x + (N % x != 0);
}

void func() {
	cout << min(B * getCnt(A), D * getCnt(C)) << '\n';
}

void input() {
	cin >> N >> A >> B >> C >> D;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}