#include <iostream>
#include <algorithm>
using namespace std;

long long N, M;

void input() {
	cin >> N >> M;
	cout << abs(N - M) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}