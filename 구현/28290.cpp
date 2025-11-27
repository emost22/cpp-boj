#include <iostream>
#include <string>
using namespace std;

const string inout[2] = { "fdsajkl;", "jkl;fdsa" };
const string outin[2] = { "asdf;lkj", ";lkjasdf" };
const string stair = "asdfjkl;";
const string rstair = ";lkjfdsa";

string str;

string getKey(string x) {
	if (find(begin(inout), end(inout), x) != end(inout)) return "in-out";
	if (find(begin(outin), end(outin), x) != end(outin)) return "out-in";
	if (stair == x) return "stairs";
	if (rstair == x) return "reverse";
	return "molu";
}

void func() {
	cout << getKey(str) << '\n';
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