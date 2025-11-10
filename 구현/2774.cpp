#include <iostream>
#include <unordered_set>
using namespace std;

int x;

void func() {
	unordered_set<int> s;
	while (x) {
		s.insert(x % 10);
		x /= 10;
	}

	cout << s.size() << '\n';
	s.clear();
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}