#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (!N) {
		cout << "0\n";
		return;
	}

	int ret = 1;
	ll now = 1LL;
	while (1) {
		if (now >= N) break;
		now <<= 1;
		ret++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}