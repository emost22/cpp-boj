#include <iostream>
using namespace std;

void input() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a += (b + c + d);
	cout << a / 60 << '\n' << a % 60 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}