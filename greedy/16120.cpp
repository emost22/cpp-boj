#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'P') cnt++;
		else {
			if (cnt >= 2 && i < N - 1 && str[i + 1] == 'P') {
				cnt--;
				i++;
			}
			else {
				cout << "NP\n";
				return;
			}
		}
	}

	if (cnt == 1) cout << "PPAP\n";
	else cout << "NP\n";
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}