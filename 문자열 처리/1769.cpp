#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	for (int t = 0; ; t++) {
		N = str.size();
		if (N == 1) {
			cout << t << '\n';
			if (!((str[0] - '0') % 3)) {
				cout << "YES\n";
				return;
			}
			else {
				cout << "NO\n";
				return;
			}
		}

		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += (str[i] - '0');
		}

		str = to_string(sum);
	}
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}