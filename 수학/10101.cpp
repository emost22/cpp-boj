#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 3
using namespace std;

int list[MAX];

void func() {
	if (list[0] + list[1] + list[2] != 180) cout << "Error\n";
	else if (list[0] != list[1] && list[1] != list[2] && list[2] != list[0]) cout << "Scalene\n";
	else if (list[0] == list[1] && list[1] == list[2]) cout << "Equilateral\n";
	else cout << "Isosceles\n";
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