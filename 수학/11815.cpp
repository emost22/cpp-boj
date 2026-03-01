#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll s = sqrt(N);
	if (s * s == N) cout << "1 ";
	else cout << "0 ";
}

void input() {
	cin >> N;
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