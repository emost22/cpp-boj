#include <iostream>
using namespace std;

int N, M;

void input() {
	int a, b;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b;
		N -= (a * b);
	}

	if (N == 0) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}