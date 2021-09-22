#include <iostream>
using namespace std;

int sum = 1;
int N;

void input() {
	int x;
	cin >> N;
	while (N--) {
		cin >> x;
		sum += (x - 1);
	}

	cout << sum << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}