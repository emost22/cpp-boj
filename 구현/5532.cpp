#include <iostream>
#include <algorithm>
using namespace std;

int L, A, B, a, b;

void input() {
	cin >> L >> A >> B >> a >> b;
	cout << L - max(A / a + (A % a ? 1 : 0), B / b + (B % b ? 1 : 0)) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}