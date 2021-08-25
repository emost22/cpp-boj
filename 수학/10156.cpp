#include <iostream>
using namespace std;

int cost, cnt, now;

void input() {
	cin >> cost >> cnt >> now;
	now -= (cost * cnt);

	if (now >= 0) cout << "0\n";
	else cout << -now << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}