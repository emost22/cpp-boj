#include <iostream>
#include <string>
using namespace std;

int A, B, N, M;

void func() {
	string ret = "";
	while (N) {
		ret = to_string(N % B) + " " + ret;
		N /= B;
	}

	cout << ret << '\n';
}

void input() {
	int x;
	cin >> A >> B >> M;
	while (M--) {
		cin >> x;
		N = N * A + x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}