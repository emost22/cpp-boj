#include <iostream>
using namespace std;

int x, y;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> x >> y;
	if (x > 0 && y > 0) cout << "1\n";
	else if (x > 0 && y < 0) cout << "4\n";
	else if (x < 0 && y>0) cout << "2\n";
	else cout << "3\n";

	return 0;
}