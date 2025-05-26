#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;

ll N;

void func() {
	for (ll i = 2; i <= MAX; i++) {
		if (N % i) continue;
		
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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