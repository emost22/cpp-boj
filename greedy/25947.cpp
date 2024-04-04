#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int list[MAX];
int N, b, a;

void func() {
	sort(list, list + N);
	
	int l = 0;
	int ret = 0;
	int sum = 0;
	int cnt = 0;
	for (int r = 0; r < N; r++) {
		if (cnt < a) {
			cnt++;
			sum += (list[r] >> 1);
		}
		else {
			sum += ((list[r] + list[l++]) >> 1);
		}

		if (b < sum) {
			cout << r << '\n';
			return;
		}
	}

	cout << N << '\n';
}

void input() {
	cin >> N >> b >> a;
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