#include <iostream>
#include <string>
using namespace std;

string str1, str2;
string ans1, ans2, ans3, ans4, ans5;
int N;

void func() {
	for (int i = 0; i < N; i++) {
		int x = str1[i] - '0';
		int y = str2[i] - '0';

		ans1 += ((x & y) + '0');
		ans2 += ((x | y) + '0');
		ans3 += ((x ^ y) + '0');
		ans4 += ((1 - x) + '0');
		ans5 += ((1 - y) + '0');
	}

	cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n' << ans4 << '\n' << ans5 << '\n';
}

void input() {
	cin >> str1 >> str2;
	N = str1.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}