#include <iostream>
using namespace std;
typedef long long ll;

ll lt, wt, le, we;

void func() {
	ll ret = lt * wt - le * we;
	if (ret > 0) cout << "TelecomParisTech\n";
	else if (ret < 0) cout << "Eurecom\n";
	else cout << "Tie\n";
}

void input() {
	cin >> lt >> wt >> le >> we;
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