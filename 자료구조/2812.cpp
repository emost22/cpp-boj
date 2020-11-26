#include <iostream>
#include <queue>
#include <string>
using namespace std;

deque<char> q;
string str;
int N, K;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> str;
	for (int i = 0; i < N; i++) {
		while (K && !q.empty() && q.back() < str[i]) {
			K--;
			q.pop_back();
		}
		q.push_back(str[i]);
	}
	while (K--) {
		q.pop_back();
	}

	while (!q.empty()) {
		cout << q.front();
		q.pop_front();
	}
	cout << '\n';

	return 0;
}