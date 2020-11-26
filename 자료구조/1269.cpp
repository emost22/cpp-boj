#include <iostream>
#include <set>
using namespace std;

set<int> s;
int N, M;

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		cin >> x;
		if (s.find(x) == s.end()) {
			s.insert(x);
		}
		else s.erase(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << s.size() << '\n';

	return 0;
}
