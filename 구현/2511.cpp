#include <iostream>
#define MAX 10
using namespace std;

int a[MAX], b[MAX];

void func() {
	int last = 0;
	int pa = 0;
	int pb = 0;
	for (int i = 0; i < MAX; i++) {
		if (a[i] > b[i]) {
			pa += 3;
			last = 1;
		}
		else if (a[i] < b[i]) {
			pb += 3;
			last = -1;
		}
		else {
			pa++;
			pb++;
		}
	}

	cout << pa << ' ' << pb << '\n';
	if (pa > pb) cout << "A\n";
	else if (pa < pb) cout << "B\n";
	else {
		if (last == 1) cout << "A\n";
		else if (last == -1) cout << "B\n";
		else cout << "D\n";
	}
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < MAX; i++) {
		cin >> b[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}