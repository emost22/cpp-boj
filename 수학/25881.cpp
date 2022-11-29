#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> list;
int basic, add;
int N;

void func() {
	for (int i = 0; i < N; i++) {
		cout << list[i] << ' ' << min(1000, list[i]) * basic + max(list[i] - 1000, 0) * add << '\n';
	}
}

void input() {
	int x;
	cin >> basic >> add >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		list.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}