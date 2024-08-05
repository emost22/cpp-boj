#include <iostream>
#include <vector>
#define MAX 13
using namespace std;

vector<int> v[MAX];

void func() {
	for (int i = 1; i < MAX; i++) {
		int flag = 0;
		for (auto next : v[i]) {
			flag |= (1 << (v[next].size() - 1));
		}

		if (flag == 7) {
			cout << i << '\n';
			return;
		}
	}
}

void input() {
	int x, y;
	for (int i = 1; i < MAX; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}