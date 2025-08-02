#include <iostream>
using namespace std;

int d, n, s, p;

void func() {
	if (d + n * p < n * s) cout << "parallelize\n";
	else if (d + n * p == n * s) cout << "does not matter\n";
	else cout << "do not parallelize\n";
}

void input() {
	cin >> d >> n >> s >> p;
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