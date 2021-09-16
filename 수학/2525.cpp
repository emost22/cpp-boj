#include <iostream>
using namespace std;

int m, s;
int diff;

void input() {
	cin >> m >> s >> diff;
	s += diff;
	m += (s / 60);
	s %= 60;
	m %= 24;
	cout << m << ' ' << s << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}