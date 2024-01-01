#include <iostream>
#include <string>
using namespace std;

string str[2] = { "Bye", "Good" };
int N;

void func() {
	cout << str[!((N + 1) % (N % 100))] << '\n';
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