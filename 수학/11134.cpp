#include <iostream>
using namespace std;

int N, C;

void func() {
	cout << N / C + (N % C != 0) << '\n';
}

void input() {
	cin >> N >> C;
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