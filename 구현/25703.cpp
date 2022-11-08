#include <iostream>
#include <string>
using namespace std;

int N;

void func() {
	cout << "int a;\n";
	cout << "int *ptr = &a;\n";
	string s = "**";
	for (int i = 2; i <= N; i++) {
		cout << "int " + s + "ptr" + to_string(i) + " = &ptr" + (i > 2 ? to_string(i - 1) : "") + ";\n";
		s += '*';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}