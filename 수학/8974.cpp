#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

vector<int> v;
int a, b;

void init() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j <= i; j++) {
			v.push_back(i);
		}
	}
}

void func() {
	init();

	int ret = 0;
	for (int i = a - 1; i < b; i++) {
		ret += v[i];
	}
	cout << ret << '\n';
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