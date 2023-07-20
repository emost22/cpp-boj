#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

int list[MAX];

void func() {
	sort(list, list + MAX);
	if (list[2] >= list[0] + list[1]) cout << "Invalid\n";
	else if (list[0] == list[1] && list[1] == list[2]) cout << "Equilateral\n";
	else if (list[0] == list[1] || list[0] == list[2] || list[1] == list[2]) cout << "Isosceles\n";
	else cout << "Scalene\n";
}

void input() {
	cin >> list[0] >> list[1] >> list[2];
	if (!list[0] && !list[1] && !list[2]) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}