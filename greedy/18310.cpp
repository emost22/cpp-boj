#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;

int list[MAX];
int N;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);

	cout << list[(N - 1) / 2] << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}