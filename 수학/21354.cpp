#include <iostream>
#define AP 7
#define PP 13
using namespace std;

int A, P;

void func() {
	int aret = A * AP;
	int pret = P * PP;
	if (aret > pret) cout << "Axel\n";
	else if (aret < pret) cout << "Petra\n";
	else cout << "lika\n";
}

void input() {
	cin >> A >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}