#include <iostream>
#include <stack>
using namespace std;

int N, M;

void func() {
	stack<int> b, f;

	char c;
	int x;
	int now = -1;
	while (M--) {
		cin >> c;
		if (c == 'B') {
			if (b.empty()) continue;
			if (now == -1) continue;
			f.push(now);
			now = b.top();
			b.pop();
		}
		else if (c == 'F') {
			if (f.empty()) continue;
			if (now == -1) continue;
			b.push(now);
			now = f.top();
			f.pop();
		}
		else if (c == 'A') {
			cin >> x;

			while (!f.empty()) f.pop();
			if (now != -1) b.push(now);
			now = x;
		}
		else {
			stack<int> tmp;

			while (!b.empty()) {
				int t = b.top();
				b.pop();

				if (!tmp.empty() && tmp.top() == t) continue;
				tmp.push(t);
			}

			while (!tmp.empty()) {
				b.push(tmp.top());
				tmp.pop();
			}
		}
	}

	cout << now << '\n';
	if (b.empty()) cout << "-1\n";
	else {
		while (!b.empty()) {
			cout << b.top() << ' ';
			b.pop();
		}
		cout << '\n';
	}

	if (f.empty()) cout << "-1\n";
	else {
		while (!f.empty()) {
			cout << f.top() << ' ';
			f.pop();
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}