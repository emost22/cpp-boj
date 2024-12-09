#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x, y;
int k, len;

void func() {
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		cnt += x[i] == y[i];
	}

	cout << min(k, cnt) + len - cnt - max(0, k - cnt) << '\n';
}

void input() {
	cin >> k >> x >> y;
	len = x.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}