#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

double list[MAX];
int N;

void func() {
	sort(list, list + N);

	double ret = list[0];
	for (int i = 1; i < N; i++) {
		ret = (ret + list[i]) / 2;
	}

	cout << fixed; cout.precision(6);
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}