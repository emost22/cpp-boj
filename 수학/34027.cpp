#include <iostream>
#include <cmath>
using namespace std;

int N;

void func() {
	int s = sqrt(N);
	if (s * s == N) cout << "1\n";
	else cout << "0\n";
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