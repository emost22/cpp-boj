#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;

void func() {
	if (next_permutation(str.begin(), str.end())) {
		cout << str << '\n';
	}
	else cout << "0\n";
}

void input(){
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}