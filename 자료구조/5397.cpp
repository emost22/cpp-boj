#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> l, r;

void func() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {
			if (l.empty()) continue;
			r.push(l.top());
			l.pop();
		}
		else if (str[i] == '>') {
			if (r.empty()) continue;
			l.push(r.top());
			r.pop();
		}
		else if (str[i] == '-') {
			if (l.empty()) continue;
			l.pop();
		}
		else {
			l.push(str[i]);
		}
	}
}

void print() {
	while (!l.empty()) {
		r.push(l.top());
		l.pop();
	}

	while (!r.empty()) {
		cout << r.top();
		r.pop();
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> str;
		func();
		print();
	}

	return 0;
}