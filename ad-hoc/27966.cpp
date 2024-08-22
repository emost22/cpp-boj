#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	cout << N - 1LL + (N - 2LL) * (N - 1LL) << '\n';
	for (int i = 2; i <= N; i++) {
		cout << "1 " << i << '\n';
	}
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