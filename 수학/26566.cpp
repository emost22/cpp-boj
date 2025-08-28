#include <iostream>
#define PI 3.1415926535897932384626433832795028
using namespace std;

double a, p1, r, p2;

void func() {
	if (PI * r * r / p2 < a / p1) cout << "Slice of pizza\n";
	else cout << "Whole pizza\n";
}

void input() {
	cin >> a >> p1 >> r >> p2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}