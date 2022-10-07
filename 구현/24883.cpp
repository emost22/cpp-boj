#include <iostream>
#include <algorithm>
using namespace std;

char x;

void func() {
	if (x == 'N' || x == 'n') cout << "Naver D2\n";
	else cout << "Naver Whale\n";
}

void input() {
	cin >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}