#include <iostream>
#include <string>
using namespace std;

int N;

void func() {
	string t = to_string(N * N);
	string n = to_string(N);

	if (t.substr(t.size() - n.size()) == n) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	cin >> N;
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