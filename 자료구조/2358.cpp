#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> mx, my;
int N;

void func() {
	int ret = 0;
	for (auto m : mx) {
		ret += (m.second >= 2);
	}

	for (auto m : my) {
		ret += (m.second >= 2);
	}

	cout << ret << '\n';
}

void input() {
	int x, y;
	cin >> N;
	while (N--) {
		cin >> x >> y;
		mx[x]++;
		my[y]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}