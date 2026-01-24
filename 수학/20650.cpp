#include <iostream>
#include <algorithm>
#define MAX 7
using namespace std;

int list[MAX];

void func() {
	sort(list, list + MAX);

	cout << list[0] << ' ' << list[1] << ' ' << list[MAX - 1] - list[0] - list[1] << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
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