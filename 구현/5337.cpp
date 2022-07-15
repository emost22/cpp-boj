#include <iostream>
#include <string>
using namespace std;

string str = ".  .   .\n|  | _ | _. _ ._ _  _\n|/\\|(/.|(_.(_)[ | )(/.";

void print() {
	cout << str << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	print();

	return 0;
}