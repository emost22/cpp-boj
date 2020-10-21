#include <iostream>
using namespace std;

bool func1(int a, int n) {
	if (n%a == 0) return true;
	else return false;
}

bool func2(int a, int b, int n) {
	if (n%a == 0) return true;
	for (int i = 0; a*i <= n; i++) {
		if (func1(b, n - a*i)) return true;
	}

	return false;
}

bool func3(int a, int b, int c, int n) {
	if (n%a == 0) return true;
	for (int i = 0; a*i <= n; i++) {
		if (func2(b, c, n - a*i)) return true;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C, N;
	cin >> A >> B >> C >> N;
	if (func3(A, B, C, N)) cout << "1\n";
	else cout << "0\n";

	return 0;
}