#include <iostream>
using namespace std;

int cnt[5];
int N;

void func() {
	for (int i = 1; i <= 4; i++) {
		cout << 'Q' << i << ": " << cnt[i] << '\n';
	}
	cout << "AXIS: " << cnt[0] << '\n';
}

void input() {
	int x, y;
	cin >> N;
	while (N--) {
		cin >> x >> y;
		if (!x || !y) cnt[0]++;
		else if (x > 0 && y > 0) cnt[1]++;
		else if (x < 0 && y > 0) cnt[2]++;
		else if (x < 0 && y < 0) cnt[3]++;
		else cnt[4]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}