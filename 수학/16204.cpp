#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;

void input() {
	cin >> N >> M >> K;
	cout << min(M, K) + min(N - M, N - K) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}