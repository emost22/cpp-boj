#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int N;

void func() {
	int order, x;
	for (int i = 0; i < N; i++) {
		cin >> order;
		if (order == 1) {
			cin >> x;
			s.push(x);
		}
		else if (order == 2) {
			if (s.empty()) cout << "-1\n";
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (order == 3) {
			cout << s.size() << '\n';
		}
		else if (order == 4) {
			if (s.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else {
			if (s.empty()) cout << "-1\n";
			else cout << s.top() << '\n';
		}
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