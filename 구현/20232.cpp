#include <iostream>
#include <string>
#define A "ITMO"
#define B "SPbSU"
#define C "PetrSU, ITMO"
using namespace std;

string str[] = { A, B, B, A, A, B, A, A, A, A, A, C, B, B, A, A, A, A, B, A, A, A, A, B, A };

void input() {
	int N;
	cin >> N;
	cout << str[N - 1995] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}