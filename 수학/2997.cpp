#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

int list[MAX];

void func() {
	sort(list, list + MAX);

	int diff = list[1] - list[0];
	if (diff == list[2] - list[1]) cout << list[2] + diff << '\n';
	else if (diff < list[2] - list[1]) cout << list[1] + diff << '\n';
	else cout << list[0] + list[2] - list[1] << '\n';
}

void input() {
	cin >> list[0] >> list[1] >> list[2];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}