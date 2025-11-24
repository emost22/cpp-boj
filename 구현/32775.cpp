#include <iostream>
using namespace std;

const char* ret[2] = { "high speed rail", "flight" };
int s, f;

void func() {
	cout << ret[s > f] << '\n';
}

void input() {
	cin >> s >> f;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}