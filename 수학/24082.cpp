#include <iostream>
using namespace std;

void input() {
	int N;
	cin >> N;
	cout << N * N * N << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}