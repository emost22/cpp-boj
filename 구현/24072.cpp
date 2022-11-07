#include <iostream>
using namespace std;

void input() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << (a <= c && c < b) ? 1 : 0 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}