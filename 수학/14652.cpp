#include <iostream>
using namespace std;

void input() {
	int N, M, K;
	cin >> N >> M >> K;
	cout << K / M << ' ' << K % M << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}