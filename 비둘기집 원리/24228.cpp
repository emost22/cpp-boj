#include <iostream>
using namespace std;
typedef long long ll;

ll N, R;

void func() {
	cout << N + (R << 1) - 1 << '\n';
}

void input() {
	cin >> N >> R;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}