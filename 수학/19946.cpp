#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll N;

void func() {
	int ret = 64;
	while (!(N & 1)) {
		ret--;
		N >>= 1;
	}

	cout << ret << '\n';
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