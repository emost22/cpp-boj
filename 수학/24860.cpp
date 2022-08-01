#include <iostream>
using namespace std;
typedef long long ll;

ll va, ja, vb, jb, v, d, j;

void input() {
	cin >> va >> ja >> vb >> jb >> v >> d >> j;
	cout << (va * ja + vb * jb) * (v * d * j) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}