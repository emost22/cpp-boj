#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, U, D;

void func() {
	int u = 0;
	int d = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] == 1) u++;
		else if (list[i] == 2) d++;
	}

	if (u + N - (u + d) < U || d + N - (u + d) < D) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		if (list[i] == 1) cout << 'U';
		else if (list[i] == 2) cout << 'D';
		else if (u < U) {
			u++;
			cout << 'U';
		}
		else {
			d++;
			cout << 'D';
		}
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> U >> D;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}