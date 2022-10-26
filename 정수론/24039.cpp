#include <iostream>
#include <vector>
#define MAX 10610
using namespace std;

vector<int> prime;
bool isPrime[MAX];
int N;

void init() {
	for (int i = 2; i * i < MAX; i++) {
		if (isPrime[i]) continue;
		prime.push_back(i);
		for (int j = 2; i * j < MAX; j++) {
			isPrime[i * j] = true;
		}
	}
}

void func() {
	int len = prime.size();
	for (int i = 0; i < len - 1; i++) {
		int ret = prime[i] * prime[i + 1];
		if (N < ret) {
			cout << ret << '\n';
			return;
		}
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}