#include <iostream>
#define SOLVED 1000
#define UNION 8000
#define LEVEL 260
using namespace std;

int N, U, L;

bool chkBoj(int n) {
	return n >= SOLVED;
}

bool chkMaple(int u, int l) {
	return u >= UNION || l >= LEVEL;
}

void func() {
	if (!chkBoj(N)) cout << "Bad\n";
	else if (chkMaple(U, L)) cout << "Very Good\n";
	else cout << "Good\n";
}

void input() {
	cin >> N >> U >> L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}