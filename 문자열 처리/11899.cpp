#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;
string str;
int N;

void func() {
	for (int i = 0; i < N; i++) {
		if (str[i] == ')') {
			if (!s.empty() && s.top() == '(') s.pop();
			else s.push(str[i]);
		}
		else s.push(str[i]);
	}

	cout << s.size() << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}