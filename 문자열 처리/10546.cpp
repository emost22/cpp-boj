#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string list[100000], comp[100000];
int N;

void func() {
	int idx = -1;
	for (int i = 0; i < N - 1; i++) {
		if (list[i] != comp[i]) {
			idx = i;
			break;
		}
	}

	if (idx == -1) cout << list[N - 1] << '\n';
	else cout << list[idx] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> comp[i];
	}
	sort(list, list + N);
	sort(comp, comp + N - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}