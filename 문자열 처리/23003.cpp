#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func(int tc) {
	cout << "Case #" << tc << ": ";
	int pre = 0;
	int order = 0;
	for (int i = 0; i < N; i++) {
		if (pre < str[i]) {
			order++;
		}
		else {
			order = 1;
		}
		cout << order << ' ';
		pre = str[i];
	}
	cout << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}