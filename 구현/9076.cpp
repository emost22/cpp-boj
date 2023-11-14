#include <iostream>
#include <algorithm>
#define MAX 5
using namespace std;

int list[MAX];

void func() {
	sort(list, list + MAX);
	if (list[3] - list[1] >= 4) {
		cout << "KIN\n";
	}
	else {
		cout << list[1] + list[2] + list[3] << '\n';
	}
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}