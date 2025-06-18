#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000001
using namespace std;

vector<int> primes;
bool chk[MAX];
int l, r;

void init() {
	for (int i = 2; i < MAX; i++) {
		if (chk[i]) continue;
		primes.push_back(i);
		for (int j = 2; i * j < MAX; j++) {
			chk[i * j] = true;
		}
	}
}

void func() {
	cout << upper_bound(primes.begin(), primes.end(), r) - lower_bound(primes.begin(), primes.end(), l) << "\n\n";
}

void input() {
	cin >> r;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	while (cin >> l) {
		input();
		func();
	}

	return 0;
}