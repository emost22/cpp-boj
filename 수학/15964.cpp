#include <iostream>
using namespace std;
typedef long long ll;

ll x, y;

void input() {
	cin >> x >> y;
	cout << (x + y) * (x - y) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}