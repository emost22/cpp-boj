#include <iostream>
#include <string>
#define MAX 101
using namespace std;

string list[MAX], str;
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (str == list[i]) ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> str >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}