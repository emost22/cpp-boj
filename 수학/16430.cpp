#include <iostream>
using namespace std;

void input() {
	int N, M;
	cin >> N >> M;
	cout << M - N << ' ' << M << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}