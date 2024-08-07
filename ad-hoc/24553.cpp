#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (N % 10) cout << "0\n";
	else cout << "1\n";
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