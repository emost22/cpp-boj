#include <iostream>
#define MAX 2001
using namespace std;

bool chk[MAX][MAX];
int d1, d2;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void func() {
	int ans = 0;
	for (int i = d1; i <= d2; i++) {
		for (int j = 1; j <= i; j++) {
			int g = gcd(i, j);

			if (chk[i / g][j / g]) continue;
			
			chk[i / g][j / g] = true;
			ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> d1 >> d2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}