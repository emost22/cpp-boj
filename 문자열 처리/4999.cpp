#include <iostream>
#include <string>
using namespace std;

string str, ans;

void input() {
	cin >> ans >> str;

	if (ans.size() >= str.size()) cout << "go\n";
	else cout << "no\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	input();

	return 0;
}