#include <iostream>
#include <algorithm>
using namespace std;

double h, w;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> h >> w;
	double com1 = min(h / 3, w);
	double com2 = min(h, w / 3);
	double com3 = min(h / 2, w / 2);
	cout << max(com1, max(com2, com3)) << '\n';

	return 0;
}