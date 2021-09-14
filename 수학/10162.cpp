#include <iostream>
using namespace std;

int N, a, b, c;

void input() {
	cin >> N;
	a = N / 300;
	N %= 300;
	b = N / 60;
	N %= 60;
	c = N / 10;
	N %= 10;

	if (N) cout << "-1\n";
	else cout << a << ' ' << b << ' ' << c << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}