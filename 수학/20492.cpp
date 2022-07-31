#include <iostream>
using namespace std;

void input() {
	int N;
	cin >> N;
	cout << (int)(N * 0.78) << ' ' << (int)(N * 0.8 + N * 0.2 * 0.78) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}