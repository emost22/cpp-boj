#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> m;
int N;

void func() {
	string str;
	int x;
	while (N--) {
		cin >> str >> x;
		m[str] += x;
	}

	for (auto p : m) {
		if (p.second == 5) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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