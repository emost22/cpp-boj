#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (s.empty()) s.push(x);
		else {
			while (!s.empty() && s.top() <= x) {
				s.pop();
			}
			s.push(x);
		}
	}
	cout << s.size() << '\n';

	return 0;
}