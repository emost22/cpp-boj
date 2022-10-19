#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	N += 3071;
	str.push_back(N / 4096 + 234);
	str.push_back(N / 64 % 64 + 128);
	str.push_back(N % 64 + 128);
	cout << str << '\n';
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