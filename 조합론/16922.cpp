#include <iostream>
#include <set>
using namespace std;

set<int> s;
int list[4];
int N;

void init() {
	list[0] = 1;
	list[1] = 5;
	list[2] = 10;
	list[3] = 50;
}

void func(int idx, int cnt, int sum) {
	if (cnt == N) {
		if (sum > 0) s.insert(sum);
		return;
	}

	for (int i = idx; i < 4; i++) {
		func(i, cnt + 1, sum + list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	init();
	func(0, 0, 0);
	cout << s.size() << '\n';

	return 0;
}