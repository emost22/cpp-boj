#include<iostream>
using namespace std;
typedef long long ll;

ll K, N;

void func() {
	if (N == 1) {
		cout << "-1\n";
		return;
	}

	int ret = N * K / (N - 1);
	if ((N * K) % (N - 1)) cout << ret + 1 << '\n';
	else cout << ret << '\n';
}

void input() {
	cin >> K >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}