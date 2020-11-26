#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<double> s;
string str;
double alphabet[26], N;

void addnum(double x, double y) {
	s.push(x + y);
}

void subnum(double x, double y) {
	s.push(x - y);
}

void mulnum(double x, double y) {
	s.push(x*y);
}

void divnum(double x, double y) {
	s.push(x / y);
}

void func() {
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			s.push(alphabet[str[i] - 'A']);
		}
		else {
			double y = s.top();
			s.pop();
			double x = s.top();
			s.pop();

			if (str[i] == '*') {
				mulnum(x, y);
			}
			else if (str[i] == '+') {
				addnum(x, y);
			}
			else if (str[i] == '-') {
				subnum(x, y);
			}
			else {
				divnum(x, y);
			}
		}
	}

	cout << s.top() << '\n';
}

void input() {
	cin >> N >> str;
	for (int i = 0; i < N; i++) {
		cin >> alphabet[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed; cout.precision(2);

	input();
	func();

	return 0;
}