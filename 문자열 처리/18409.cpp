#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}