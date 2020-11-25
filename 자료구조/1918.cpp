#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack<char> st;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') cout << str[i];
		else if (str[i] == '(') st.push(str[i]);
		else if (str[i] == ')'){
			while (st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << '\n';

	return 0;
}