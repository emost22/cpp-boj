#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3;
int list[N];

void func() {
	vector<int> v;
	for (int i = 1; i < (1 << N); i++) {
		int sum = 1;
		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;
			sum *= list[j];
		}
		v.push_back(sum);
	}

	sort(v.begin(), v.end(), [](int a, int b) {
		if ((a & 1) == (b & 1)) return a > b;
		if (a & 1) return true;
		return false;
	});

	cout << v[0] << '\n';
}

void input() {
	cin >> list[0] >> list[1] >> list[2];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}