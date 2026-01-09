#include <iostream>
#include <vector>
#define MAX 5000
using namespace std;

vector<int> v;
const int price[] = { 0, 500, 800, 1000 };

void func() {
	int ret = MAX;
	for (auto x : v) {
		ret -= price[x];
	}

	cout << ret << '\n';
}

void input() {
	int x;
	while (cin >> x) {
		v.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}