#include <iostream>
#include <string>
using namespace std;

string n = "7890123456";
string c = "JKLABCDEFGHI";
int x;

void func() {
	cout << c[(x - 1) % 12] << n[(x - 1) % 10] << '\n';
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();
	func();

	return 0;
}