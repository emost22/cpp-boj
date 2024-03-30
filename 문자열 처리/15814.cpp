#include <iostream>
#include <string>
using namespace std;

string str;
int M;

void func() {
	int x, y;
	while (M--) {
		cin >> x >> y;
		swap(str[x], str[y]);
	}

	cout << str << '\n';
}

void input() {
	cin >> str >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}