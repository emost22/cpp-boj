#include <iostream>
using namespace std;

int N;

void func() {
	int cnt = 0;
	while (N) {
		cnt += (N & 1);
		N >>= 1;
	}

	cout << (cnt == 1 ? 1 : 0) << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}