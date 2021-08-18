#include <iostream>
using namespace std;

int a, r;

void input() {
	cin >> a >> r;
	cout << r * 2 - a << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}