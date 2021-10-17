#include <iostream>
#include <deque>
using namespace std;

deque<char> dq;
int N;

void print() {
	while (!dq.empty()) {
		cout << dq.front();
		dq.pop_front();
	}
	cout << '\n';
}

void input() {
	char ch;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> ch;
		if (dq.empty()) dq.push_back(ch);
		else {
			if (ch <= dq.front()) dq.push_front(ch);
			else dq.push_back(ch);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		print();
	}

	return 0;
}