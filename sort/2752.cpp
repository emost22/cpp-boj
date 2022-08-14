#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

int list[MAX];

void func() {
	cout << list[0] << ' ' << list[1] << ' ' << list[2] << '\n';
}

void input() {
	cin >> list[0] >> list[1] >> list[2];
	sort(list, list + MAX);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}