#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

vector<int> v;
int list[MAX];
int N;

void func() {
	int maxValue = 0;
	for (int i = 1; i <= N; i++) {
		maxValue = max(maxValue, list[i]);
		if (i == maxValue) v.push_back(i);
	}

	int pre = 0;
	cout << v.size() << '\n';
	for (auto x : v) {
		cout << x - pre << ' ';
		for (int i = pre + 1; i <= x; i++) cout << i << ' ';
		cout << '\n';
		pre = x;
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}