#include <iostream>
#include <string>
using namespace std;

string g;
int x;

int getScore(int lv, string grade) {
	if (grade == "miss") return 0;
	if (grade == "bad") return lv * 200;
	if (grade == "cool") return lv * 400;
	if (grade == "great") return lv * 600;
	return lv * 1000;
}

void func() {
	cout << getScore(x, g) << '\n';
}

void input() {
	cin >> x >> g;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}