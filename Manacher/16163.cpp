#include <iostream>
#include <algorithm>
#include <string>
#define MAX 4000001
using namespace std;
typedef long long ll;

string str;
int palindrome[MAX];
int N;

void func() {
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (ll)((palindrome[i] + 1) / 2);
	}

	cout << ans << '\n';
}

void manacher() {
	int p = 0;
	int r = 0;
	for (int i = 0; i < N; i++) {
		if (i <= r) palindrome[i] = min(palindrome[p * 2 - i], r - i);
		else palindrome[i] = 0;

		while (i - palindrome[i] - 1 >= 0 && i + palindrome[i] + 1 < N && str[i - palindrome[i] - 1] == str[i + palindrome[i] + 1]) palindrome[i]++;

		if (r < i + palindrome[i]) {
			r = i + palindrome[i];
			p = i;
		}
	}
}

void input() {
	string tmp;
	cin >> tmp;
	N = tmp.size();
	for (int i = 0; i < N; i++) {
		str += '#';
		str += tmp[i];
	}
	str += '#';
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	manacher();
	func();

	return 0;
}