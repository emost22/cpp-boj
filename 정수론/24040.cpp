#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (!(N % 9LL) || (N % 3LL == 2)) cout << "TAK\n";
	else cout << "NIE\n";
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