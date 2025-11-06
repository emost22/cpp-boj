#include <iostream>
#include <string>
#define COL 2
#define BAR 5
using namespace std;

string str;

void func() {
	int ret = 0;
	for (auto x : str) {
		ret += (x == '_');
	}
	
	cout << ret * BAR + str.size() + COL << '\n';
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}