#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string str1, str2;

void func() {
	ll x = 0;
	ll y = 0;
	int len = str1.size();
	for (int i = 0; i < len; i++) {
		x += (ll)(str1[i] - 48LL);
	}

	len = str2.size();
	for (int i = 0; i < len; i++) {
		y += (ll)(str2[i] - 48LL);
	}

	cout << x * y << '\n';
}

void input() {
	cin >> str1 >> str2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}