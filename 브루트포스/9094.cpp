#include <iostream>
#include <cmath>
using namespace std;

int N;
double M;

void func() {
	int ret = 0;
	for (double i = 1; i < N - 1; i++) {
		for (double j = i + 1; j < N; j++) {
			double x = (i * i + j * j + M) / (i * j);
			ret += (floor(x) == x);
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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