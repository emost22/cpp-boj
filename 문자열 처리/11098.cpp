#include <iostream>
#include <string>
using namespace std;

string str, ansstr;
int ans, price, N;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price >> str;
		if (ans < price) {
			ans = price;
			ansstr = str;
		}
	}

	cout << ansstr << '\n';
	ans = 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}