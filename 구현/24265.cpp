#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	cout << N * (N - 1) / 2LL << "\n2\n";
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