#include <iostream>
#include <string>
using namespace std;

string a, b;

bool isOtherWord() {
	int cnt[26] = { 0, };
	for (auto x : a) {
		cnt[x - 'A']++;
	}

	for (auto x : b) {
		if (!cnt[x - 'A']) return true;
		cnt[x - 'A']--;
	}
	return false;
}

void func() {
	if (isOtherWord()) {
		cout << "-1\n";
		return;
	}

	int len = a.size();
	int cnt = 0;
	for (int i = len - 1; i >= 0; i--) {
		cnt += (a[i] == b[len - 1 - cnt]);
	}
	cout << len - cnt << '\n';
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}