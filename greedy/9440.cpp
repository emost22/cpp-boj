#include <iostream>
#include <algorithm>
#define MAX 15
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);
	int zero = 0;
	for (int i = 0; i < N; i++) {
		zero += list[i] == 0;
	}

	if (zero == 1) {
		swap(list[0], list[2]);
	}
	else if (zero >= 2) {
		swap(list[0], list[zero]);
		swap(list[1], list[zero + 1]);
	}

	int x = 0;
	int y = 0;
	for (int i = 0; i < N; i++) {
		if (i & 1) y = y * 10 + list[i];
		else x = x * 10 + list[i];
	}

	cout << x + y << '\n';
}

void input() {
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) return 0;
		input();
		func();
	}
}