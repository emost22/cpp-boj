#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int list[MAX];
int N, A, B, C;

void func() {
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});

	int sumValue = C;
	int sumPrice = A;
	int ret = sumValue / sumPrice;
	for (int i = 0; i < N; i++) {
		sumValue += list[i];
		sumPrice += B;
		ret = max(ret, sumValue / sumPrice);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> A >> B >> C;
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