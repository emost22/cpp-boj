#include <iostream>
using namespace std;

int N;
int x, y;

bool isVertex(int x, int y) {
	return (x == 1 && y == 1) || (x == 1 && y == N) || (x == N && y == 1) || (x == N && y == N);
}

bool isLine(int x, int y) {
	return x == 1 || x == N || y == 1 || y == N;
}

void func() {
	if (N == 1) cout << "0\n";
	else if (isVertex(x, y)) cout << "2\n";
	else if (isLine(x, y)) cout << "3\n";
	else cout << "4\n";
}

void input() {
	cin >> N >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}