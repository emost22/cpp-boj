#include <iostream>
#include <string>
using namespace std;

string str[2] = { "YONSEI", "Leading the Way to the Future" };

void input() {
	int N;
	cin >> N;
	cout << str[N] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}