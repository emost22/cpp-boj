#include <iostream>
#include <unordered_set>
using namespace std;

int N;

int getNext(int x) {
	int ret = 0;
	while (x) {
		int tmp = x % 10;
		ret += (tmp * tmp);
		x /= 10;
	}

	return ret;
}

void func() {
	unordered_set<int> s;
	s.insert(N);

	int nx = N;
	while (1) {
		nx = getNext(nx);
		if (nx == 1) {
			cout << "HAPPY\n";
			return;
		}

		if (s.find(nx) != s.end()) {
			cout << "UNHAPPY\n";
			return;
		}

		s.insert(nx);
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