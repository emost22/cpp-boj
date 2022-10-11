#include <iostream>
#include <algorithm>
using namespace std;

int cnt[3];

void input() {
	int x;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		cnt[x]++;
	}

	cout << (cnt[1] > cnt[2] ? 1 : 2) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}