#include <iostream>
using namespace std;

string x, y;
int len1, len2;

void func() {
	if (len1 != len2) {
		cout << "-1\m";
		return;
	}

	int ret = 0;
	int idx1 = 0;
	int idx2 = 0;
	while (1) {
		while (idx1 < len1 && x[idx1] == 'a') idx1++;
		while (idx2 < len2 && y[idx2] == 'a') idx2++;
		if (idx1 >= len1 || idx2 >= len2) break;
		ret += abs(idx1++ - idx2++);
	}
	cout << ret << '\n';
}

void input() {
	cin >> x >> y;
	len1 = x.size();
	len2 = y.size();
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