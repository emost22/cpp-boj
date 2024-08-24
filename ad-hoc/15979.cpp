#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int N, M;

void func() {
	cout << min(2, gcd(N, M)) << '\n';
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