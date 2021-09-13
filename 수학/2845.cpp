#include <iostream>
using namespace std;

int N, M;

void input() {
	int x;
	int sum = 0;
	cin >> N >> M;
	sum = N * M;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		cout << x - sum << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}