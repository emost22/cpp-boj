#include <iostream>
#include <deque>
using namespace std;

deque<int> q;
int N;

void func() {
	int type, x;
	while (N--) {
		cin >> type;

		if (type == 1) {
			cin >> x;
			q.push_front(x);
		}
		else if (type == 2) {
			cin >> x;
			q.push_back(x);
		}
		else if (type == 3) {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if (type == 4) {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.back() << '\n';
				q.pop_back();
			}
		}
		else if (type == 5) {
			cout << q.size() << '\n';
		}
		else if (type == 6) {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (type == 7) {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << '\n';
		}
		else {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << '\n';
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