#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 100001
using namespace std;

stack<int> s[4];
int list[MAX];
int N;

void func() {
	s[0].push(0);
	s[1].push(0);
	s[2].push(0);
	s[3].push(0);
	for (int i = 1; i <= N; i++) {
		int minIdx = -1;
		int minDiff = 1e9;
		for (int j = 0; j < 4; j++) {
			if (s[j].empty()) {
				minIdx = j;
				break;
			}

			if (s[j].top() > list[i]) continue;

			int diff = abs(s[j].top() - list[i]);
			if (diff < minDiff) {
				minDiff = diff;
				minIdx = j;
			}
		}

		if (minIdx == -1) {
			cout << "NO\n";
			return;
		}
		
		s[minIdx].push(list[i]);
	}

	cout << "YES\n";
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}